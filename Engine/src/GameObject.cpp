
#include "MathEngine.h"
#include "GameObject.h"
#include "Game.h"
#include "TextureObject.h"


namespace Azul
{

	GameObject::GameObject(GraphicsObject *pGraphicsObject)
		: poPos{new Vec3(0,0,0)},
		poGraphicsObject(pGraphicsObject),
		scale(1.0f)
	{
		assert(pGraphicsObject);
		assert(poPos);

		this->poWorld = new Mat4(Special::Identity);
		assert(this->poWorld);

	}
	void GameObject::SetScale(float v)
	{
		this->scale = v;
	}

	void GameObject::ChangeTexture(TextureObject* pTex)
	{
		this->poGraphicsObject->ChangeTexture(pTex);
	}

	void GameObject::SetLighting(Vec3* poLightColor, Vec3* poLightPos)
	{
		this->poGraphicsObject->SetLighting(poLightColor, poLightPos);
	}


	GameObject::~GameObject()
	{
		delete this->poPos;
		delete this->poGraphicsObject;
		delete this->poWorld;
	}

	Mat4 *GameObject::GetWorld()
	{
		return this->poWorld;
	}

	void GameObject::SetPos(Vec3 v)
	{
		poPos->set(v);
	}

	void GameObject::Update()
	{

		static float angle = 0.0f;
		angle += 0.01f;

		Trans TransA(poPos->x(), poPos->y(), poPos->z());
		Scale ScaleA(scale, scale, scale);
		Rot RotA(Rot1::Z, angle);

		*this->poWorld = ScaleA * RotA * TransA;

		// PUSH to Graphics object
		this->poGraphicsObject->SetWorld(*this->poWorld);
	}

	void GameObject::SetWorld(Mat4 *world)
	{
		assert(world);
		*this->poWorld = *world;
	}

	void GameObject::Draw()
	{
		// ---------------------------------------------
		//  Transfer data to the constant buffer
		//    CPU ---> GPU
		//    World, View, Projection Matrix
		//    Set Shader
		//    Render
		// ---------------------------------------------
		this->poGraphicsObject->Render();

	}

}

// --- End of File ---
