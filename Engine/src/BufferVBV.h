//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef BUFFER_VBV_H
#define BUFFER_VBV_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferVBV
	{
	public:
		BufferVBV() = delete;
		BufferVBV(const BufferVBV &r) = delete;
		BufferVBV &operator=(const BufferVBV &) = delete;
		virtual ~BufferVBV();

		BufferVBV(size_t numBytes, size_t _strideSize, void *pData);

		void SetActive(VertexSlot slot);

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t		 numBytes;
		size_t		 strideSize;
		size_t		 offset;
		ID3D11Buffer *poBufferVBV;
		bool         bCreate;
	};
}

#endif

//--- End of File ---
