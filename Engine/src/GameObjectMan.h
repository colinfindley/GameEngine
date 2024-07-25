
#ifndef GAME_OBJECT_MAN_H
#define GAME_OBJECT_MAN_H

#include "GameObject.h"
#include "PCSTree.h"

namespace Azul
{

	// Singleton
	class GameObjectMan
	{
	public:
		static void Add(GameObject *pObj);
		static void Draw();
		static void Update();
		static void ChangeTexture(TextureObject* pTex);
		static void SetLighting(Vec3* poLightColor, Vec3* poLightPos);

		static void Create();
		static void Destroy();

		GameObjectMan(const GameObjectMan &) = delete;
		GameObjectMan &operator = (const GameObjectMan &) = delete;

		~GameObjectMan();

	private:
		GameObjectMan();

		static GameObjectMan *privGetInstance();

		// data
		PCSTree *poRootTree;
	};

}

#endif


// --- End of File ---
