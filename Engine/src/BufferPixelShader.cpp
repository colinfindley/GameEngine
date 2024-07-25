//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "BufferPixelShader.h"
#include "DirectXDeviceMan.h"
#include "ShaderObject.h"

namespace Azul
{
	BufferPixelShader::BufferPixelShader(size_t _numBytes, void *pData)
		: codeSize{_numBytes},
		poPixelShader{nullptr},
		bCreate{false}
	{
		assert(pData);
		this->privCreate(pData);
	}

	void BufferPixelShader::privCreate(void *pData)
	{
		// in case set was called before
		assert(this->bCreate == false);
		this->bCreate = true;

		assert(pData);

		HRESULT hr;
		hr = DirectXDeviceMan::GetDevice()->CreatePixelShader(pData, 
															  this->codeSize, 
															  nullptr, 
															  &this->poPixelShader);
		assert(SUCCEEDED(hr));
		assert(this->poPixelShader);

		assert(std::string("ps_5_0") == (ShaderObject::GetLatestProfile_PixelShader()));

	}

	void BufferPixelShader::SetActive()
	{
		// slow down... check this function (VS,CS,PS) types
		DirectXDeviceMan::GetContext()->PSSetShader(this->poPixelShader, nullptr, 0);
	}

	BufferPixelShader::~BufferPixelShader()
	{
		SafeRelease(this->poPixelShader);
	}

}

//--- End of File ---
