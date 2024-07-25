
#include "GraphicsObject.h"
#include "MathEngine.h"
#include "Mesh.h"
#include "TextureObject.h"

using namespace Azul;

GraphicsObject::GraphicsObject(Mesh *_pMesh, ShaderObject *_pShaderObj)
	: pMesh(_pMesh),
	pShaderObj(_pShaderObj),
	pTex(nullptr)
{
	this->poWorld = new Mat4(Special::Identity);
	assert(_pMesh);
	assert(_pShaderObj);
}

GraphicsObject::~GraphicsObject()
{
	if (pTex != nullptr)
	{
		pTex->referenceCount--;
	}

	delete this->poWorld;
}

void GraphicsObject::Render()
{
	this->SetState();
	this->SetDataGPU();
	this->Draw();
	this->RestoreState();
}

Mesh *GraphicsObject::GetMesh() const
{
	return this->pMesh;
}

Mat4 &GraphicsObject::GetWorld()
{
	return *this->poWorld;
}

void GraphicsObject::SetWorld(Mat4 &_world)
{
	*this->poWorld = _world;
}

void GraphicsObject::ChangeTexture(TextureObject* _pTex)
{
}

void GraphicsObject::SetLighting(Vec3* poLightColor, Vec3* poLightPos) {}


// --- End of File ---
