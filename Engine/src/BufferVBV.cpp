//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "BufferVBV.h"
#include "DirectXDeviceMan.h"

namespace Azul
{
	BufferVBV::BufferVBV(size_t _numBytes, size_t _strideSize, void *pData)
		: numBytes{_numBytes},
		strideSize{_strideSize},
		offset{0},
		poBufferVBV{nullptr},
		bCreate{false}
	{
		assert(pData);
		this->privCreate(pData);
	}

	void BufferVBV::privCreate(void *pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);

		// Create an initialize the vertex buffer.
		D3D11_BUFFER_DESC vertexBufferDesc{0};
		D3D11_SUBRESOURCE_DATA resourceData{0};

		// type of buffer
		vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
		vertexBufferDesc.ByteWidth = this->numBytes;
		vertexBufferDesc.CPUAccessFlags = 0;
		vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;

		resourceData.pSysMem = pData;

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateBuffer(&vertexBufferDesc, &resourceData, &this->poBufferVBV);

		assert(SUCCEEDED(hr));
		assert(this->poBufferVBV);
	}

	void BufferVBV::SetActive(VertexSlot slot)
	{
		// slow down... check this function (VS,CS,PS) types
		DirectXDeviceMan::GetContext()->IASetVertexBuffers((uint32_t)slot,
														   1,
														   &this->poBufferVBV,
														   &this->strideSize,
														   &this->offset);
	}

	BufferVBV::~BufferVBV()
	{
		SafeRelease(this->poBufferVBV);
	}

}

//--- End of File ---
