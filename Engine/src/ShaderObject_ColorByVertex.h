//--------------------------------------------------------------

//--------------------------------------------------------------

#ifndef SHADER_OBJECT_COLOR_BY_VERTEX_H
#define SHADER_OBJECT_COLOR_BY_VERTEX_H

#include "ShaderObject.h"
#include "BufferCBV.h"
#include "BufferVertexShader.h"
#include "BufferPixelShader.h"
#include "BufferInputLayout.h"

using namespace Azul;

class ShaderObject_ColorByVertex : public ShaderObject
{
public:

public:
	ShaderObject_ColorByVertex() = delete;
	ShaderObject_ColorByVertex(const ShaderObject_ColorByVertex &) = delete;
	ShaderObject_ColorByVertex &operator = (const ShaderObject_ColorByVertex &) = delete;
	~ShaderObject_ColorByVertex();

	ShaderObject_ColorByVertex(ShaderObject_ColorByVertex::Name _name);

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
