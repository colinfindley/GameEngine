
#ifndef GRAPHICS_OBJECT_H
#define GRAPHICS_OBJECT_H

#include "MathEngine.h"
#include "ShaderObject.h"
#include "TextureObject.h"
#include "GraphicsObject_Abstract.h"

using namespace Azul;

class Mesh;

class GraphicsObject : public GraphicsObject_Abstract
{
public:
	void Render();
	void SetWorld(Mat4 &_world);
	virtual void ChangeTexture(TextureObject* pTex);
	virtual void SetLighting(Vec3* poLightColor, Vec3* poLightPos);

	Mesh *GetMesh() const;
	Mat4 &GetWorld();

	virtual ~GraphicsObject() override;

protected:
	GraphicsObject(Mesh *pMesh, ShaderObject *pShaderObj);

	GraphicsObject() = delete;
	GraphicsObject(const GraphicsObject &) = delete;
	GraphicsObject &operator = (const GraphicsObject &) = delete;

protected:
	Mesh *pMesh;
	Mat4 *poWorld;
	ShaderObject *pShaderObj;
	TextureObject* pTex;
};

#endif

// --- End of File ---
