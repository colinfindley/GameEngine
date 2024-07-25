
#ifndef GAME_OBJECT_Cube_H
#define GAME_OBJECT_Cube_H

#include "MathEngine.h"
#include "Mesh.h"
#include "ShaderObject.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "GameObject.h"
#include "TextureObject.h"

namespace Azul
{

	class GameObjectCube : public GameObject
	{
	public:
		GameObjectCube(GraphicsObject* poGraphicsObject);
		void Update();
		void ChangeTexture(TextureObject* pTex);

	};



}
#endif


// --- End of File ---
