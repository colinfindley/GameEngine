//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef CAMERA_MAN_H
#define CAMERA_MAN_H 

#include "ManBase.h"
#include "CameraNode.h"
#include "Camera.h"

class CameraNodeMan : public ManBase
{
	//----------------------------------------------------------------------
	// Static Methods
	//----------------------------------------------------------------------
public:
	static void Create(int reserveNum = 0, int reserveGrow = 1);
	static void Destroy();

	static CameraNode* Add(Camera::Name name, Camera* pCamera);
	static CameraNode* Find(Camera::Name name);

	static void Remove(CameraNode* pNode);
	static void Dump();

	static Camera* GetActiveCamera();
	static void SetActiveCamera(Camera::Name name);
	
	static void Update();

	static void SetHelper(Vec3& up, Vec3& tar, Vec3& pos);
	static void GetHelper(Vec3& up, Vec3& tar, Vec3& pos, Vec3& upNorm, Vec3& forwardNorm, Vec3& rightNorm);

	//----------------------------------------------------------------------
	// Private methods
	//----------------------------------------------------------------------
private:
	static CameraNodeMan* privGetInstance();

	~CameraNodeMan();
	CameraNodeMan(int reserveNum, int reserveGrow);

	//----------------------------------------------------------------------
	// Override Abstract methods
	//----------------------------------------------------------------------
protected:
	DLink* derivedCreateNode() override;

	//----------------------------------------------------------------------
	// Data: unique data for this manager 
	//----------------------------------------------------------------------
private:
	CameraNode* poNodeCompare;
	static CameraNodeMan* posInstance;
	Camera* pActiveCamera;

};

#endif

// --- End of File ---
