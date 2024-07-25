//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef MESH_Cross_H
#define MESH_Cross_H

#include "Mesh.h"
#include "BufferIBV.h"
#include "BufferVBV.h"

class MeshCross : public Mesh
{
public:
	MeshCross();
	MeshCross(const MeshCross&) = delete;
	MeshCross& operator = (MeshCross&) = delete;
	virtual ~MeshCross();

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
