//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef CUBE_MODEL_H
#define CUBE_MODEL_H

#include "Mesh.h"
#include "BufferIBV.h"
#include "BufferVBV.h"

class MeshCube : public Mesh
{
public:
	MeshCube();
	MeshCube(const MeshCube &) = delete;
	MeshCube &operator = (MeshCube &) = delete;
	virtual ~MeshCube();

	virtual void ActivateMesh() override;
	virtual void RenderIndexBuffer() override;

	// Data
	BufferVBV VBVBuffer_pos;
	BufferVBV VBVBuffer_color;
	BufferVBV VBVBuffer_norm;
	BufferVBV VBVBuffer_tex;

	BufferIBV IBVBuffer;
};

#endif

// --- End of File ---
