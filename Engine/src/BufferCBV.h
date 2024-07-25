//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef BUFFER_CBV_H
#define BUFFER_CBV_H

#include <d3d11.h>
#include "ShaderMappings.h"

namespace Azul
{
	class BufferCBV
	{
	public:
		BufferCBV() = delete;
		BufferCBV(const BufferCBV &r) = delete;
		BufferCBV &operator=(const BufferCBV &) = delete;
		virtual ~BufferCBV();

		BufferCBV(size_t structSize);

		void Transfer(void *pBuff);
		void SetActive(ConstantBufferSlot slot);

	private:
		void privCreate(size_t structSize);

		// ----------------------
		//  Data
		// ----------------------
	public:
		size_t       structSize;
		ID3D11Buffer *poBufferCBV;
		bool         bCreate;
	};
}

#endif

//--- End of File ---
