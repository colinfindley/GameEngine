//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "BufferVertexShader.h"
#include "DirectXDeviceMan.h"
#include "ShaderObject.h"

namespace Azul
{
	BufferVertexShader::BufferVertexShader(size_t _numBytes, void *pData)
		: codeSize{_numBytes},
		poVertexShader{nullptr},
		bCreate{false}
	{
		assert(pData);
		this->privCreate(pData);
	}

	void BufferVertexShader::privCreate(void *pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreateVertexShader(pData, 
															   this->codeSize,
															   nullptr, 
															   &this->poVertexShader);
		assert(SUCCEEDED(hr));
		assert(this->poVertexShader);

		assert(std::string("vs_5_0") == (ShaderObject::GetLatestProfile_VertexShader()));
	}

	void BufferVertexShader::SetActive()
	{
		// slow down... check this function (VS,CS,PS) types
		DirectXDeviceMan::GetContext()->VSSetShader(this->poVertexShader, nullptr, 0);
	}

	BufferVertexShader::~BufferVertexShader()
	{
		SafeRelease(this->poVertexShader);
	}

}

//--- End of File ---
