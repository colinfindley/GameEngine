
#ifndef GAME_OBJECT_DIAMOND_H
#define GAME_OBJECT_DIAMOND_H

#include "MathEngine.h"
#include "Mesh.h"
#include "ShaderObject.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "GameObject.h"
#include "TextureObject.h"

namespace Azul
{

	class GameObjectDiamond : public GameObject
	{
	public:
		GameObjectDiamond(GraphicsObject* poGraphicsObject);
		void Update();

	};



}
#endif


// --- End of File ---
