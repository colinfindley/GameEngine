
#ifndef GAME_OBJECT_PYRAMID_H
#define GAME_OBJECT_PYRAMID_H

#include "MathEngine.h"
#include "Mesh.h"
#include "ShaderObject.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "GameObject.h"

namespace Azul
{

	class GameObjectPyramid : public GameObject
	{
	public:
		GameObjectPyramid(GraphicsObject* poGraphicsObject);
		void setRotation(float radius);
		void setSpeed(float speed);
		void Update();
		void ChangeTexture(TextureObject* pTex);


	private:
		float radius = 5.0f;
		float speed = .006f;
	};



}
#endif


// --- End of File ---
