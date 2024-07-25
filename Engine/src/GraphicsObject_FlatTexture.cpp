//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include <d3d11.h>
#include "MathEngine.h"
#include "Mesh.h"
#include "GraphicsObject_FlatTexture.h"
#include "CameraNodeMan.h"


using namespace Azul;

// ---------------------------------------------
//  Transfer data to the constant buffer
//    CPU ---> GPU
//    World, View, Projection Matrix
// ---------------------------------------------
GraphicsObject_FlatTexture::GraphicsObject_FlatTexture(Mesh *mesh, 
													   ShaderObject *pShaderObj, 
													   TextureObject *_pTex)
	: GraphicsObject(mesh, pShaderObj),
	pTex(_pTex)
{
	_pTex->referenceCount++;
	assert(pTex);
}

void GraphicsObject_FlatTexture::SetState()
{
	// Future - settings to directX
	// set texture
	this->pTex->ActivateTexture();
}

void GraphicsObject_FlatTexture::SetDataGPU()
{
	pShaderObj->ActivateShader();
	pShaderObj->ActivateCBV();
	pShaderObj->TransferWorldViewProj(CameraNodeMan::GetActiveCamera(), this->poWorld);
	pMesh->ActivateMesh();
}

void GraphicsObject_FlatTexture::Draw()
{
	pMesh->RenderIndexBuffer();
}

void GraphicsObject_FlatTexture::RestoreState()
{
	// Future - Undo settings to directX
}

void GraphicsObject_FlatTexture::ChangeTexture(TextureObject* newTexture)
{
	assert(pTex->poTextureRV != nullptr);
	this->pTex = newTexture;
}


// --- End of File ---
