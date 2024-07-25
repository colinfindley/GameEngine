//--------------------------------------------------------------

//--------------------------------------------------------------

#ifndef SHADER_OBJECT_FLAT_TEXTURE_H
#define SHADER_OBJECT_FLAT_TEXTURE_H

#include "ShaderObject.h"
#include "BufferCBV.h"
#include "BufferVertexShader.h"
#include "BufferPixelShader.h"
#include "BufferInputLayout.h"

class ShaderObject_FlatTexture : public ShaderObject
{
public:

public:
	ShaderObject_FlatTexture() = delete;
	ShaderObject_FlatTexture(const ShaderObject_FlatTexture &) = delete;
	ShaderObject_FlatTexture &operator = (const ShaderObject_FlatTexture &) = delete;
	~ShaderObject_FlatTexture();

	ShaderObject_FlatTexture( ShaderObject_FlatTexture::Name _name);

	virtual void ActivateShader() override;
	virtual void ActivateCBV() override;
	virtual void TransferWorldViewProj(Camera *pCam, Mat4 *pWorld) override;

	// ---------------------------------------------
	// 	   Data:
	// ---------------------------------------------

	BufferCBV ConstantBuff_Projection;
	BufferCBV ConstantBuff_World;
	BufferCBV ConstantBuff_View;

	BufferVertexShader VertexShader;
	BufferPixelShader  PixelShader;
	BufferInputLayout  InputLayout;

};

#endif

// --- End of File ---
