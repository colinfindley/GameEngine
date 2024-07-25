//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "CameraNodeMan.h"
#include "CameraNull.h"
#include "ManBase.h"
#include "DLinkMan.h"

CameraNodeMan* CameraNodeMan::posInstance = nullptr;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
CameraNodeMan::CameraNodeMan(int reserveNum, int reserveGrow)
	: ManBase(new DLinkMan(), new DLinkMan(), reserveNum, reserveGrow)
{
	// Preload the reserve
	this->proFillReservedPool(reserveNum);

	// -----------------------
	// Compare Node create
	// -----------------------
	Camera* pCamera = new CameraNull();
	assert(pCamera);
	this->poNodeCompare = new CameraNode();
	assert(this->poNodeCompare);
	this->poNodeCompare->Set(Camera::Name::NULL_CAMERA, pCamera);
}

CameraNodeMan::~CameraNodeMan()
{
	delete this->poNodeCompare;
	this->poNodeCompare = nullptr;

	// iterate through the list and delete
	Iterator* pIt = this->baseGetActiveIterator();

	DLink* pNode = pIt->First();

	// Walk through the nodes
	while (!pIt->IsDone())
	{
		CameraNode* pDeleteMe = (CameraNode*)pIt->Curr();
		pNode = pIt->Next();
		delete pDeleteMe;
	}

	pIt = this->baseGetReserveIterator();

	pNode = pIt->First();

	// Walk through the nodes
	while (!pIt->IsDone())
	{
		CameraNode* pDeleteMe = (CameraNode*)pIt->Curr();
		pNode = pIt->Next();
		delete pDeleteMe;
	}
}

//----------------------------------------------------------------------
// Static Methods
//----------------------------------------------------------------------
void CameraNodeMan::Create(int reserveNum, int reserveGrow)
{
	// make sure values are ressonable 
	assert(reserveNum >= 0);
	assert(reserveGrow > 0);

	// initialize the singleton here
	assert(posInstance == nullptr);

	// Do the initialization
	if (posInstance == nullptr)
	{
		posInstance = new CameraNodeMan(reserveNum, reserveGrow);
	}
}

void CameraNodeMan::Destroy()
{
	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
	assert(pMan != nullptr);
	AZUL_UNUSED_VAR(pMan);

	delete CameraNodeMan::posInstance;
	CameraNodeMan::posInstance = nullptr;
}

CameraNode* CameraNodeMan::Add(Camera::Name name, Camera* pCamera)
{
	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();

	assert(pCamera);

	CameraNode* pNode = (CameraNode*)pMan->baseAddToFront();
	assert(pNode != nullptr);

	// Initialize the date
	pNode->Set(name, pCamera);

	return pNode;
}

CameraNode* CameraNodeMan::Find(Camera::Name _name)
{
	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
	assert(pMan != nullptr);

	// Compare functions only compares two Nodes

	// So:  Use the Compare Node - as a reference
	//      use in the Compare() function
	Camera* pCamera = pMan->poNodeCompare->GetCamera();
	assert(pCamera);

	pCamera->name = _name;

	CameraNode* pData = (CameraNode*)pMan->baseFind(pMan->poNodeCompare);
	return pData;
}

void CameraNodeMan::Remove(CameraNode* pNode)
{
	assert(pNode != nullptr);

	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
	assert(pMan != nullptr);

	pMan->baseRemove(pNode);
}

void CameraNodeMan::Dump()
{
	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
	assert(pMan != nullptr);

	pMan->baseDump();
}

Camera* CameraNodeMan::GetActiveCamera()
{
	return CameraNodeMan::privGetInstance()->pActiveCamera;
}

void CameraNodeMan::SetActiveCamera(Camera::Name name)
{
	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
	pMan->pActiveCamera = pMan->Find(name)->GetCamera();
}

void CameraNodeMan::Update()
{
	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
	pMan->pActiveCamera->updateCamera();
}



void CameraNodeMan::SetHelper(Vec3& up, Vec3& tar, Vec3& pos)
{
	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
	pMan->pActiveCamera->SetHelper(up, tar, pos);
}

void CameraNodeMan::GetHelper(Vec3& up, Vec3& tar, Vec3& pos, Vec3& upNorm, Vec3& forwardNorm, Vec3& rightNorm)
{
	CameraNodeMan* pMan = CameraNodeMan::privGetInstance();
	pMan->pActiveCamera->GetHelper(up, tar, pos, upNorm, forwardNorm, rightNorm);
}

//----------------------------------------------------------------------
// Private methods
//----------------------------------------------------------------------
CameraNodeMan* CameraNodeMan::privGetInstance()
{
	// Safety - this forces users to call Create() first before using class
	assert(posInstance != nullptr);

	return posInstance;
}

//----------------------------------------------------------------------
// Override Abstract methods
//----------------------------------------------------------------------
DLink* CameraNodeMan::derivedCreateNode()
{
	DLink* pNodeBase = new CameraNode();
	assert(pNodeBase != nullptr);

	return pNodeBase;
}

// --- End of File ---
