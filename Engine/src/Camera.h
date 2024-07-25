//--------------------------------------------------------------

//--------------------------------------------------------------

#ifndef CAMERA_H
#define CAMERA_H

#include "MathEngine.h"

using namespace Azul;

class Camera : public Align16
{

public:
	enum class Name
	{
		CENTER,
		TOP,
		BOTTOM,
		RIGHT,
		OPPOSITE,
		LEFT,
		NULL_CAMERA,
		NOT_INITIALIZED
	};


	// Default constructor
	Camera();
	Camera(const Camera &) = delete;
	Camera &operator = (const Camera &) = delete;
	~Camera() = default;

	// Setup on single camera
	void setPerspective(const float FieldOfView_Degs, const float AspectRatio, const float NearDist, const float FarDist);
	void setOrientAndPosition(const Vec3 &Up_vect, const Vec3 &inLookAt_pt, const Vec3 &pos_pt);

	// update camera system
	virtual void updateCamera(void);

	// Get the matrices for rendering
	Mat4 &getViewMatrix();
	Mat4 &getProjMatrix();

	// helper functions
	void GetHelper(Vec3 &up, Vec3 &tar, Vec3 &pos, Vec3 &upNorm, Vec3 &forwardNorm, Vec3 &rightNorm);
	void SetHelper(Vec3 &up, Vec3 &tar, Vec3 &pos);

	// accessors
	void getPos(Vec3 &outPos) const;
	void getDir(Vec3 &outDir) const;
	void getUp(Vec3 &outUp) const;
	void getLookAt(Vec3 &outLookAt) const;
	void getRight(Vec3 &outRight) const;


	void SetName(Camera::Name _name);

	char* GetName();

	Camera::Name name;


	// Why no SETS for Pos, Dir, Up, LookAt and Right?
	//   They have to be adjusted _together_ in setOrientAndPosition()

protected:  // methods should never be public
	virtual void privUpdateProjectionMatrix(void);
	virtual void privUpdateViewMatrix(void);


private:  // data  (Keep it private)

	// Projection Matrix
	Mat4	projMatrix;
	Mat4	viewMatrix;

	// camera unit vectors (up, dir, right)
	Vec3	vUp;
	Vec3	vDir;
	Vec3	vRight;  // derived by up and dir
	Vec3	vPos;
	Vec3	vLookAt;

	// Define the frustum inputs
	float	nearDist;
	float	farDist;
	float	fovy;  // aka view angle along y axis
	float	aspectRatio;

	//float tiltSpeed = .09f;
	//float panSpeed = .09f;
	//float zoomSpeed = .03f;
};

#endif

// --- End of File ---