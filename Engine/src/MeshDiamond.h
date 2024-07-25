//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef MESH_Diamond_H
#define MESH_Diamond_H

#include "Mesh.h"
#include "BufferIBV.h"
#include "BufferVBV.h"

class MeshDiamond : public Mesh
{
public:
	MeshDiamond();
	MeshDiamond(const MeshDiamond&) = delete;
	MeshDiamond& operator = (MeshDiamond&) = delete;
	virtual ~MeshDiamond();

	virtual void ActivateMesh() override;
	virtual void RenderIndexBuffer() override;

	// Data
	BufferVBV VBVBuffer_pos;
	BufferVBV VBVBuffer_color;
	BufferVBV VBVBuffer_tex;
	BufferVBV VBVBuffer_norm;

	BufferIBV IBVBuffer;
};

#endif

// --- End of File ---
