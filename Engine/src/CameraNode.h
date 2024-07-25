//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef CAMERA_NODE_H
#define CAMERA_NODE_H

#include "DLink.h"
#include "Camera.h"

class CameraNode : public DLink
{
public:
	CameraNode();
	CameraNode(const Camera&) = delete;
	CameraNode& operator = (const Camera&) = delete;
	virtual ~CameraNode();

	void Set(Camera::Name name, Camera* pCamera);
	Camera* GetCamera();

	virtual char* GetName() override;
	virtual void Wash() override;
	virtual bool Compare(DLink* pTargetNode) override;
	virtual void Dump() override;

private:
	void privClear();

	//--------------------------------------------------
	// Data
	//--------------------------------------------------
	Camera* poCamera;
};

#endif

// --- End of File ---
