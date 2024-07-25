//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef BUFFER_PIXEL_SHADER_H
#define BUFFER_PIXEL_SHADER_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferPixelShader
	{
	public:
		BufferPixelShader() = delete;
		BufferPixelShader(const BufferPixelShader &r) = delete;
		BufferPixelShader &operator=(const BufferPixelShader &) = delete;
		virtual ~BufferPixelShader();

		BufferPixelShader(size_t numBytes, void *pData);

		void SetActive();

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t		      codeSize;
		ID3D11PixelShader *poPixelShader;
		bool              bCreate;
	};
}

#endif

//--- End of File ---
