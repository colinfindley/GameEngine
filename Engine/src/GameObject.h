
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "MathEngine.h"
#include "Mesh.h"
#include "ShaderObject.h"
#include "GraphicsObject.h"
#include "TextureObject.h"
#include "PCSNode.h"

namespace Azul
{

	class GameObject : public PCSNode
	{
	public:
		GameObject() = delete;
		GameObject(const GameObject &) = delete;
		GameObject &operator = (const GameObject &) = delete;
		virtual ~GameObject();

		GameObject(GraphicsObject *poGraphicsObject);

		virtual void Update();
		void Draw();

		Mat4 *GetWorld();
		void SetWorld(Mat4 *world);
		void SetPos(Vec3 v);
		void SetScale(float v);
		virtual void ChangeTexture(TextureObject* pTex);
		void SetLighting(Vec3* poLightColor, Vec3* poLightPos);

	protected:
		float scale;
		Vec3 *poPos;
		Mat4 *poWorld;
		GraphicsObject *poGraphicsObject;
	};

}
#endif


// --- End of File ---
