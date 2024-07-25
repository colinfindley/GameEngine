//--------------------------------------------------------------

//--------------------------------------------------------------

#ifndef SHADER_OBJECT_CONST_COLOR_H
#define SHADER_OBJECT_CONST_COLOR_H

#include "ShaderObject.h"
#include "BufferCBV.h"
#include "BufferVertexShader.h"
#include "BufferPixelShader.h"
#include "BufferInputLayout.h"

class ShaderObject_ConstColor : public ShaderObject
{
public:

public:
	ShaderObject_ConstColor() = delete;
	ShaderObject_ConstColor(const ShaderObject_ConstColor &) = delete;
	ShaderObject_ConstColor &operator = (const ShaderObject_ConstColor &) = delete;
	~ShaderObject_ConstColor();

	ShaderObject_ConstColor( ShaderObject_ConstColor::Name _name);

	virtual void ActivateShader() override;
	virtual void ActivateCBV() override;
	virtual void TransferWorldViewProj(Camera *pCam, Mat4 *pWorld) override;

	virtual void TransferColor(Vec3 *pColor) override;

	// ---------------------------------------------
	// 	   Data:
	// ---------------------------------------------

	BufferCBV ConstantBuff_Projection;
	BufferCBV ConstantBuff_World;
	BufferCBV ConstantBuff_View;

	BufferCBV ConstantBuff_Color;

	BufferVertexShader VertexShader;
	BufferPixelShader  PixelShader;
	BufferInputLayout  InputLayout;

};

#endif

// --- End of File ---
