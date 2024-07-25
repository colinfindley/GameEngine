//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef CAMERA_NULL_H
#define CAMERA_NULL_H

#include "Camera.h"

class CameraNull : public Camera
{
public:
	CameraNull();
	CameraNull(const Camera&) = delete;
	CameraNull &operator = (const CameraNull&) = delete;
	virtual ~CameraNull();


	virtual void updateCamera(void) override;



	// Why no SETS for Pos, Dir, Up, LookAt and Right?
	//   They have to be adjusted _together_ in setOrientAndPosition()

protected:  // methods should never be public
	virtual void privUpdateProjectionMatrix(void) override;
	virtual void privUpdateViewMatrix(void) override;


private:

};

#endif

// --- End of File ---
