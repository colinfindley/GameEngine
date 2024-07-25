
#include <d3d11.h>
#include <d3dcompiler.h>

#include "Game.h"
#include "Engine.h"
#include "MathEngine.h"
#include "Camera.h"
#include "Colors.h"
#include "GameObject.h"
#include "GameObjectPyramid.h"
#include "GameObjectCube.h"
#include "GameObjectDiamond.h"
#include "ShaderObject.h"
#include "ShaderObject_ColorByVertex.h"
#include "ShaderObject_FlatTexture.h"
#include "ShaderObject_LightTexture.h"
#include "ShaderObject_ConstColor.h"
#include "Mesh.h"
#include "MeshCube.h"
#include "MeshPyramid.h"
#include "MeshDiamond.h"
#include "MeshCross.h"
#include "GraphicsObject_ColorByVertex.h"
#include "GraphicsObject_Wireframe.h"
#include "GraphicsObject_FlatTexture.h"
#include "GraphicsObject_LightTexture.h"
#include "GraphicsObject_ConstColor.h"
#include "GameObjectMan.h"
#include "MeshNodeMan.h"
#include "TextureNodeMan.h"
#include "CameraNodeMan.h"
#include "ShaderObjectNodeMan.h"
#include "DirectXDeviceMan.h"
#include "TextureObject.h"


using namespace Azul;


Game::Game(const char *const pName, int width, int height)
	: Engine(pName, width, height)
{
}

Game::~Game()
{
}

-
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
-
bool Game::LoadContent()
{
	ShaderObjectNodeMan::Create();
	MeshNodeMan::Create();
	TextureNodeMan::Create();
	GameObjectMan::Create();
	CameraNodeMan::Create();

	// ---------------------------------
	//  Camera - Setup
	// ---------------------------------


	{
		Camera *pCenterCamera = new Camera();
		Vec3 camPos(0, -17, 2);
		Vec3 tarVect(0, 0, 0);
		Vec3 upVect(0, 1, 0);

		pCenterCamera->setOrientAndPosition(upVect, tarVect, camPos);
		pCenterCamera->setPerspective(50.0f, GetAspectRatio(), 0.1f, 1000.0f);
		CameraNodeMan::Add(Camera::Name::CENTER, pCenterCamera);
		CameraNodeMan::SetActiveCamera(Camera::Name::CENTER);
	}
	{
		Camera* pRightCamera = new Camera();
		Vec3 camPos(17, 0, 2);
		Vec3 tarVect(0, 0, 0);
		Vec3 upVect(0, 0, 1);

		pRightCamera->setOrientAndPosition(upVect, tarVect, camPos);
		pRightCamera->setPerspective(50.0f, GetAspectRatio(), 0.1f, 1000.0f);
		CameraNodeMan::Add(Camera::Name::RIGHT, pRightCamera);
	}
	{
		Camera* pOppositeCamera = new Camera();
		Vec3 camPos(0, 17, -2);
		Vec3 tarVect(0, 0, 0);
		Vec3 upVect(0, 1, 0);

		pOppositeCamera->setOrientAndPosition(upVect, tarVect, camPos);
		pOppositeCamera->setPerspective(50.0f, GetAspectRatio(), 0.1f, 1000.0f);
		CameraNodeMan::Add(Camera::Name::OPPOSITE, pOppositeCamera);
	}
	{
		Camera* pLeftCamera = new Camera();
		Vec3 camPos(-17, 0, 2);
		Vec3 tarVect(0, 0, 0);
		Vec3 upVect(0, 0, 1);

		pLeftCamera->setOrientAndPosition(upVect, tarVect, camPos);
		pLeftCamera->setPerspective(50.0f, GetAspectRatio(), 0.1f, 1000.0f);
		CameraNodeMan::Add(Camera::Name::LEFT, pLeftCamera);
	}
	{
		Camera* pTopCamera = new Camera();
		Vec3 camPos(0, 2, 19);
		Vec3 tarVect(0, 0, 0);
		Vec3 upVect(0, 1, 0);

		pTopCamera->setOrientAndPosition(upVect, tarVect, camPos);
		pTopCamera->setPerspective(50.0f, GetAspectRatio(), 0.1f, 1000.0f);
		CameraNodeMan::Add(Camera::Name::TOP, pTopCamera);
	}
	{
		Camera* pBottomCamera = new Camera();
		Vec3 camPos(0, 2, -19);
		Vec3 tarVect(0, 0, 0);
		Vec3 upVect(0, 1, 0);

		pBottomCamera->setOrientAndPosition(upVect, tarVect, camPos);
		pBottomCamera->setPerspective(50.0f, GetAspectRatio(), 0.1f, 1000.0f);
		CameraNodeMan::Add(Camera::Name::BOTTOM, pBottomCamera);
	}

	// ------------------------------------------
	//   Model + Shaders --> GraphicsObject
	// -------------------------------------------
	{
		// ---------------------------------
		//  Models
		// ---------------------------------

		Mesh *meshCube = new MeshCube();
		MeshNodeMan::Add(Mesh::Name::CUBE, meshCube);

		Mesh *meshPyramid = new MeshPyramid();
		MeshNodeMan::Add(Mesh::Name::PYRAMID, meshPyramid);

		Mesh* meshDiamond = new MeshDiamond();
		MeshNodeMan::Add(Mesh::Name::DIAMOND, meshDiamond);

		Mesh* meshCross = new MeshCross();
		MeshNodeMan::Add(Mesh::Name::CROSS, meshCross);

		//MeshNodeMan::Dump();

		// --------------------------------
		//  Shaders
		// --------------------------------
		ShaderObject *poShaderA = new ShaderObject_ColorByVertex(ShaderObject::Name::ColorByVertex);
		ShaderObjectNodeMan::Add(poShaderA);

		ShaderObject *poShaderB = new ShaderObject_FlatTexture(ShaderObject::Name::FlatTexture);
		ShaderObjectNodeMan::Add(poShaderB);

		ShaderObject *poShaderC = new ShaderObject_LightTexture(ShaderObject::Name::LightTexture);
		ShaderObjectNodeMan::Add(poShaderC);

		ShaderObject *poShaderD = new ShaderObject_ConstColor(ShaderObject::Name::ConstColor);
		ShaderObjectNodeMan::Add(poShaderD);


		//ShaderObjectNodeMan::Dump();

		// -----------------------------------
		//  Textures
		// -----------------------------------

		TextureObject *pTexA = new TextureObject(TextureObject::Name::Duckweed, L"Duckweed.tga");
		TextureNodeMan::Add(TextureObject::Name::Duckweed, pTexA);
		pTexA->SetFilter(D3D11_FILTER_ANISOTROPIC);
		pTexA->SetAddressMode(D3D11_TEXTURE_ADDRESS_WRAP);

		TextureObject *pTexB = new TextureObject(TextureObject::Name::Brick, L"RedBrick.tga");
		TextureNodeMan::Add(TextureObject::Name::Brick, pTexB);

		TextureObject *pTexC = new TextureObject(TextureObject::Name::Stone, L"Stone.tga");
		TextureNodeMan::Add(TextureObject::Name::Stone, pTexC);

		TextureObject *pTexD = new TextureObject(TextureObject::Name::Rocks, L"Rocks.tga"); 
		TextureNodeMan::Add(TextureObject::Name::Rocks, pTexD);
		pTexD->SetFilter(D3D11_FILTER_ANISOTROPIC);
		pTexD->SetAddressMode(D3D11_TEXTURE_ADDRESS_CLAMP);

		//TextureNodeMan::Dump();


		// --------------------------------
		//  Graphics Object -- needs model + shader
		// --------------------------------

		Vec3 LightColor(.9f, .1f, 0.0f);
		Vec3 LightColor1(0.0f, .9f, 0.0f);

		Vec3 LightPos(0.0f, -100.0f, 0.0f);
		Vec3 LightPos1(0.0f, 100.0f, 0.0f);
		Vec3 LightPos2(10.0f, 50.0f, 0.0f);
		Vec3 LightPos3(0.0f, 50.0f, 4.0f);




		// --------------------------------
		//  Lighting Displays Center
		// --------------------------------


		{
			GraphicsObject* pGraphicsObject = new GraphicsObject_LightTexture(meshCross,
				poShaderC,
				pTexA,
				LightColor,
				LightPos1);
			GameObject* pGameObj = new GameObject(pGraphicsObject);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(-1, 0, 0));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);

		}

		{
			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshCube,
				poShaderA,
				pTexA);
			GameObject* pGameObj = new GameObject(pGraphicsObject);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(1, 0, 0));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);

		}


		// --------------------------------
		//  Spinning Pyramids
		// --------------------------------

		

		{ 

			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshPyramid,
				poShaderA,
				pTexB);


			GameObject* pGameObj = new GameObjectPyramid(pGraphicsObject);
			((GameObjectPyramid*)pGameObj)->setRotation(11.0f);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(2, 0, 0));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

		{ 

			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshPyramid,
				poShaderA,
				pTexB);


			GameObject* pGameObj = new GameObjectPyramid(pGraphicsObject);
			((GameObjectPyramid*)pGameObj)->setRotation(13.0f);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(2, 0, 0));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

		{ 

			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshPyramid,
				poShaderA,
				pTexB);


			GameObject* pGameObj = new GameObjectPyramid(pGraphicsObject);
			((GameObjectPyramid*)pGameObj)->setRotation(15.0f);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(2, 0, 0));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

		{ 

			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshPyramid,
				poShaderA,
				pTexB);


			GameObject* pGameObj = new GameObjectPyramid(pGraphicsObject);
			((GameObjectPyramid*)pGameObj)->setRotation(17.0f);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(2, 0, 0));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}



		// --------------------------------
		//  Spinning Cubes
		// --------------------------------

		{ 

			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshCube,
				poShaderB,
				pTexB);
			GameObject* pGameObj = new GameObject(pGraphicsObject);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(-1, 0, 2));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

		{

			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshCube,
				poShaderB,
				pTexC);
			GameObject* pGameObj = new GameObject(pGraphicsObject);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(1, 0, 2));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

		{ 

			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshCube,
				poShaderB,
				pTexD);
			GameObject* pGameObj = new GameObject(pGraphicsObject);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(-1, 0, 4));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

		{ 

			GraphicsObject* pGraphicsObject = new GraphicsObject_FlatTexture(meshCube,
				poShaderB,
				pTexA);
			GameObject* pGameObj = new GameObject(pGraphicsObject);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(1, 0, 4));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

		{

			GraphicsObject* pGraphicsObject = new GraphicsObject_Wireframe(meshCube,
				poShaderA);
			GameObject* pGameObj = new GameObject(pGraphicsObject);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(-1, 0, 6));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

		{

			GraphicsObject* pGraphicsObject = new GraphicsObject_Wireframe(meshCube,
				poShaderA);
			GameObject* pGameObj = new GameObject(pGraphicsObject);
			pGameObj->SetName("Jeff");
			pGameObj->SetPos(Vec3(1, 0, 6));
			pGameObj->SetScale(2.0f);

			GameObjectMan::Add(pGameObj);
		}

	}


	return true;
}

-
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
-

Vec3 obj(0.0f, 0.0f, 0.0f);

void Game::Update(float)
{
	// ------------------------------------
	// Camera Controls
	// ------------------------------------

	Camera* pCam = CameraNodeMan::GetActiveCamera();

	// ** Change Cameras ** //

	if ((GetKeyState('1') & 0x8000))
	{
		CameraNodeMan::SetActiveCamera(Camera::Name::CENTER);
	}

	if ((GetKeyState('2') & 0x8000))
	{
		CameraNodeMan::SetActiveCamera(Camera::Name::RIGHT);
	}

	if ((GetKeyState('3') & 0x8000))
	{
		CameraNodeMan::SetActiveCamera(Camera::Name::OPPOSITE);
	}

	if ((GetKeyState('4') & 0x8000))
	{
		CameraNodeMan::SetActiveCamera(Camera::Name::LEFT);
	}

	if ((GetKeyState('5') & 0x8000))
	{
		CameraNodeMan::SetActiveCamera(Camera::Name::TOP);
	}

	if ((GetKeyState('6') & 0x8000))
	{
		CameraNodeMan::SetActiveCamera(Camera::Name::BOTTOM);
	}

	// ** Pan Camera ** //

	if ((GetKeyState('W') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
		pos = pos + 0.09f * forwardNorm;
		pCam->SetHelper(up, tar, pos);
	}

	if ((GetKeyState('A') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
		pos = pos - .02f * rightNorm;

		pCam->SetHelper(up, tar, pos);
	}
	if ((GetKeyState('D') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		pos = pos + .02f * rightNorm;

		pCam->SetHelper(up, tar, pos);
	}

	if ((GetKeyState('S') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
		pos = pos - 0.09f * forwardNorm;
		pCam->SetHelper(up, tar, pos);
	}
	
	// Tilt
	if ((GetKeyState(VK_UP) & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
		tar = tar + 0.15f * upNorm;
		pCam->SetHelper(up, tar, pos);
	}

	if ((GetKeyState(VK_DOWN) & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
		tar = tar - 0.15f * upNorm;
		pCam->SetHelper(up, tar, pos);
	}

	if ((GetKeyState(VK_RIGHT) & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
		tar = tar + 0.15f * rightNorm;
		pCam->SetHelper(up, tar, pos);
	}

	if ((GetKeyState(VK_LEFT) & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
		tar = tar - 0.15f * rightNorm;
		pCam->SetHelper(up, tar, pos);
	}


	// ** Zoom Camera ** //

	if ((GetKeyState('I') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
		pos = pos + 0.03f * forwardNorm;
		up = up + 0.03f * forwardNorm;

		pCam->SetHelper(up, tar, pos);
	}

	if ((GetKeyState('O') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//tar = obj;

		pos = pos - 0.03f * forwardNorm;
		up = up - 0.03f * forwardNorm;

		pCam->SetHelper(up, tar, pos);

	}

	// ** Rotate Camera **//

	// Right
	if ((GetKeyState('J') & 0x8000))
	{

		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//	tar = obj;

		Trans TransA(tar);
		Trans NegTrans(-tar);

		Rot RotA;
		RotA.set(Axis::AxisAngle, upNorm, +0.05f);

		Mat4 M = NegTrans * RotA * TransA;

		up = Vec4(up, 1.0f) * M;
		pos = Vec4(pos, 1.0f) * M;
		tar = Vec4(tar, 1) * M;

		pCam->SetHelper(up, tar, pos);
	}

	// Left
	if ((GetKeyState('K') & 0x8000))
	{

		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm

		//	tar = obj;

		Trans TransA(tar);
		Trans NegTrans(-tar);

		Rot RotA;
		RotA.set(Axis::AxisAngle, upNorm, -0.05f);

		Mat4 M = NegTrans * RotA * TransA;

		up = Vec4(up, 1) * M;
		pos = Vec4(pos, 1) * M;
		tar = Vec4(tar, 1) * M;

		pCam->SetHelper(up, tar, pos);
	}

	// Down
	if ((GetKeyState('M') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		//	tar = obj;


			// OK, now 3 points... pos, tar, up
			//     now 3 normals... upNorm, forwardNorm, rightNorm

		Trans TransA(tar);
		Trans NegTrans(-tar);
		Rot RotA;
		RotA.set(Axis::AxisAngle, rightNorm, 0.05f);

		Mat4 M = NegTrans * RotA * TransA;

		up = Vec4(up, 1) * M;
		pos = Vec4(pos, 1) * M;
		tar = Vec4(tar, 1) * M;

		pCam->SetHelper(up, tar, pos);
	}

	// Up
	if ((GetKeyState('I') & 0x8000))
	{
		Vec3 pos;
		Vec3 tar;
		Vec3 up;
		Vec3 upNorm;
		Vec3 forwardNorm;
		Vec3 rightNorm;

		pCam->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);

		// OK, now 3 points... pos, tar, up
		//     now 3 normals... upNorm, forwardNorm, rightNorm
		//tar = obj;

		Trans TransA(tar);
		Trans NegTrans(-tar);
		Rot RotA;
		RotA.set(Axis::AxisAngle, rightNorm, -0.05f);

		Mat4 M = NegTrans * RotA * TransA;

		up = Vec4(up, 1) * M;
		pos = Vec4(pos, 1) * M;
		tar = Vec4(tar, 1) * M;

		pCam->SetHelper(up, tar, pos);
	}

	// ------------------------------------
	// Texture Controls
	// ------------------------------------

	if ((GetKeyState('X') & 0x8000))
	{
		// Reset	
		//changeTexture = true;
		TextureObject* pTex = TextureNodeMan::Find(TextureObject::Name::Brick)->GetTexture();
		GameObjectMan::ChangeTexture(pTex);
	}

	if ((GetKeyState('Z') & 0x8000))
	{
		// Reset	
		//changeTexture = true;
		TextureObject* pTex = TextureNodeMan::Find(TextureObject::Name::Stone)->GetTexture();
		GameObjectMan::ChangeTexture(pTex);
	}

	if ((GetKeyState('C') & 0x8000))
	{
		// Reset	
		//changeTexture = true;
		TextureObject* pTex = TextureNodeMan::Find(TextureObject::Name::Duckweed)->GetTexture();
		GameObjectMan::ChangeTexture(pTex);
	}

	if ((GetKeyState('V') & 0x8000))
	{
		// Reset	
		//changeTexture = true;
		TextureObject* pTex = TextureNodeMan::Find(TextureObject::Name::Rocks)->GetTexture();
		GameObjectMan::ChangeTexture(pTex);
	}

	CameraNodeMan::Update();
	GameObjectMan::Update();

	// ------------------------------------
	// Light Controls
	// ------------------------------------



	//if ((GetKeyState('0') & 0x8000))
	//{

	//	GameObjectMan::SetLighting(&LightColor, &LightPos);
	//}

	//if ((GetKeyState('9') & 0x8000))
	//{
	//	Vec3 LightColor(1, 0, .5);
	//	Vec3 LightPos(0, 100, 50);
	//	GameObjectMan::SetLighting(&LightColor, &LightPos);
	//}

}

-
// Game::Render()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
-
void Game::Render()
{
	this->SetDefaultTargetMode();

	GameObjectMan::Draw();
}

-
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
-
void Game::UnloadContent()
{;
	ShaderObjectNodeMan::Destroy();
	MeshNodeMan::Destroy();
	TextureNodeMan::Destroy();
	GameObjectMan::Destroy();
	CameraNodeMan::Destroy();
	DirectXDeviceMan::Destroy();

}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
// 
// Clear the color and depth buffers.
//------------------------------------------------------------------
void Game::ClearDepthStencilBuffer()
{
#ifdef _DEBUG
	const Vec4 ClearColor = Azul::Colors::LightGray;
#else
	const Vec4 ClearColor = Azul::Colors::Wheat;
#endif
	float clearDepth = 1.0f;
	uint8_t clearStencil = 0;
	g_d3dDeviceContext->ClearRenderTargetView(g_d3dRenderTargetView, (const float *)&ClearColor);
	g_d3dDeviceContext->ClearDepthStencilView(g_d3dDepthStencilView, D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, clearDepth, clearStencil);
}

// --- End of File ---
