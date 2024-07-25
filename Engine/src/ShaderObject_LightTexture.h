//--------------------------------------------------------------

//--------------------------------------------------------------

#ifndef SHADER_OBJECT_LIGHT_TEXTURE_H
#define SHADER_OBJECT_LIGHT_TEXTURE_H

#include "ShaderObject.h"
#include "BufferCBV.h"
#include "BufferVertexShader.h"
#include "BufferPixelShader.h"
#include "BufferInputLayout.h"

class ShaderObject_LightTexture : public ShaderObject
{
public:
	ShaderObject_LightTexture() = delete;
	ShaderObject_LightTexture(const ShaderObject_LightTexture &) = delete;
	ShaderObject_LightTexture &operator = (const ShaderObject_LightTexture &) = delete;
	~ShaderObject_LightTexture();

	ShaderObject_LightTexture( ShaderObject_LightTexture::Name _name);

	virtual void ActivateShader() override;
	virtual void ActivateCBV() override;
	virtual void TransferWorldViewProj(Camera *pCam, Mat4 *pWorld) override;
	virtual void TransferLightPos(Vec3 *pLightPos) override;
	virtual void TransferColor(Vec3 *pColor) override;


	// ---------------------------------------------
	// 	   Data:
	// ---------------------------------------------

	BufferCBV ConstantBuff_Projection;
	BufferCBV ConstantBuff_World;
	BufferCBV ConstantBuff_View;

	BufferCBV ConstantBuff_Color;
	BufferCBV ConstantBuff_LightPos;

	BufferVertexShader VertexShader;
	BufferPixelShader  PixelShader;
	BufferInputLayout  InputLayout;
};

#endif

// --- End of File ---
