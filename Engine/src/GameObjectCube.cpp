#include "GameObjectCube.h"
#include <iostream>
#include <cmath> // For sin and cos functions

namespace Azul
{
    GameObjectCube::GameObjectCube(GraphicsObject* poGraphicsObject)
        : GameObject(poGraphicsObject) // Initialize base class
    {}


    void GameObjectCube::Update()
    {
		float trans = 0.0f;
		// goal is to update the world matrix
		static float angle = 0.0f;
		angle += 0.01f;

		Trans TransC(poPos->x(), poPos->y(), poPos->z());
		Scale ScaleA(scale, scale, scale);
		Trans TransA(trans, 0.0f, -4.0f);
		Trans TransB(Trig::sin(2.1f * angle) * 0.5f,
			Trig::cos(1.7f * angle) * 0.5f,
			Trig::sin(1.3f * angle) * Trig::cos(1.5f * angle) * 2.0f);
		Rot RotY(Rot1::Y, 0.8f * angle);
		Rot RotX(Rot1::X, 0.4f * angle);

		*this->poWorld = TransC * ScaleA * RotX * RotY * TransB * TransA;

		// PUSH to Graphics object
		this->poGraphicsObject->SetWorld(*this->poWorld);

    }

	void GameObjectCube::ChangeTexture(TextureObject* pTex)
	{
		this->poGraphicsObject->ChangeTexture(pTex);

	}

}
