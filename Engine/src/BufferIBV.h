//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef BUFFER_IBV_H
#define BUFFER_IBV_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferIBV
	{
	public:
		BufferIBV() = delete;
		BufferIBV(const BufferIBV &r) = delete;
		BufferIBV &operator=(const BufferIBV &) = delete;
		virtual ~BufferIBV();

		BufferIBV(size_t numBytes, void *pData);

		void SetActive();

	private:
		void privCreate(void *pData);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t		 numBytes;
		ID3D11Buffer *poBufferIBV;
		bool         bCreate;
	};
}

#endif

//--- End of File ---
