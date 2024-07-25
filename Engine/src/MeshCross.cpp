#include "MeshCross.h"

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "MeshCross.h"
#include "MathEngine.h"
#include "DirectXDeviceMan.h"
#include "ShaderMappings.h"

using namespace Azul;

const float XCord = .5f;
const float YCord = .1f;
const float ZCord = .15f;
const float XCordPerp = ZCord;
const float YCordPerp = YCord - .001f;
const float ZCordPerp = XCord;

// Vertex positions (scaled down by a factor of 0.5)
uint32_t g_CrossIndices[] =
{
	1, 0,2 ,
	4, 3,5 ,
	7, 6,8 ,
	10,9,11 ,
	13,12,14 ,
	16,15,17 ,
	19,18,20 ,
	22,21,23 ,
	25,24,26 ,
	28,27,29 ,
	31,30,32 ,
	34,33,35 ,
	37, 36, 38,
	40, 39, 41,
	43, 42, 44,
	46, 45, 47,
	49, 48, 50,
	52, 51, 53,
	55, 54, 56,
	58, 57, 59,
	61, 60, 62,
	64, 63, 65,
	67, 66, 68,
	70, 69, 71
};

VertexPos g_CrossVertices_pos[] = {

	// *** BACK FACE *** //

	// Triangle 0
	Vec3(-XCord,  YCord, -ZCord), // left top back
	Vec3(-XCord, -YCord, -ZCord), // left bottom back
	Vec3(XCord, -YCord,  -ZCord), // right bottom back

	// Triangle 1
	Vec3(XCord,  -YCord, -ZCord), // right bottom back
	Vec3(XCord,   YCord, -ZCord), // right top back
	Vec3(-XCord,  YCord, -ZCord), // left top back

	// *** RIGHT FACE *** //

	// Triangle 2
	Vec3(XCord, -YCord, -ZCord), // right bottom back
	Vec3(XCord, -YCord,  ZCord), // right bottom front
	Vec3(XCord,  YCord, -ZCord), // right top back

	// Triangle 3
	Vec3(XCord, -YCord,  ZCord), // right bottom front
	Vec3(XCord,  YCord,  ZCord), // right top front
	Vec3(XCord,  YCord, -ZCord), // right top back

	// *** FRONT FACE *** //

	// Triangle 4
	Vec3(XCord,  -YCord,  ZCord), // right bottom front
	Vec3(-XCord,  -YCord,  ZCord), // left bottom front
	Vec3(XCord,   YCord,  ZCord), // right top front

	// Triangle 5
	Vec3(-XCord, -YCord,  ZCord), // left bottom front
	Vec3(-XCord,  YCord,  ZCord), // left top front
	Vec3(XCord,   YCord,  ZCord), // right top front

	// *** LEFT FACE *** //

	// Triangle 6
	Vec3(-XCord, -YCord,  ZCord), // left bottom front
	Vec3(-XCord, -YCord, -ZCord), // left bottom back
	Vec3(-XCord,  YCord,  ZCord), // left top front

	// Triangle 7
	Vec3(-XCord, -YCord, -ZCord), // left bottom back
	Vec3(-XCord,  YCord, -ZCord), // left top back
	Vec3(-XCord,  YCord,  ZCord), // left top front

	// *** BOTTOM FACE *** //

	// Triangle 8
	Vec3(-XCord, -YCord,  ZCord), // left bottom front
	Vec3(XCord, -YCord,   ZCord), // right bottom front
	Vec3(XCord, -YCord,  -ZCord), // right bottom back

	// Triangle 9
	Vec3(XCord, -YCord,  -ZCord), // right bottom back
	Vec3(-XCord, -YCord, -ZCord), // left bottom back
	Vec3(-XCord, -YCord,  ZCord), // left bottom front

	// *** TOP FACE *** //

	// Triangle 10
	Vec3(-XCord,  YCord, -ZCord), // left top back
	Vec3(XCord,  YCord,  -ZCord), // right top back
	Vec3(XCord,  YCord,   ZCord), // right top front

	// Triangle 11
	Vec3(XCord,  YCord,   ZCord), // right top front
	Vec3(-XCord,  YCord,  ZCord), // left top front
	Vec3(-XCord,  YCord, -ZCord),  // left top back


	// *********** PERPENDICULAR CUBOID *********** //


	// *** BACK FACE *** //

	// Triangle 12
	Vec3(-XCordPerp,  YCordPerp, -ZCordPerp), // left top back
	Vec3(-XCordPerp, -YCordPerp, -ZCordPerp), // left bottom back
	Vec3(XCordPerp, -YCordPerp,  -ZCordPerp), // right bottom back

	// Triangle 13
	Vec3(XCordPerp,  -YCordPerp, -ZCordPerp), // right bottom back
	Vec3(XCordPerp,   YCordPerp, -ZCordPerp), // right top back
	Vec3(-XCordPerp,  YCordPerp, -ZCordPerp), // left top back

	// *** RIGHT FACE *** //

	// Triangle 14
	Vec3(XCordPerp, -YCordPerp, -ZCordPerp), // right bottom back
	Vec3(XCordPerp, -YCordPerp,  ZCordPerp), // right bottom front
	Vec3(XCordPerp,  YCordPerp, -ZCordPerp), // right top back

	// Triangle 15
	Vec3(XCordPerp, -YCordPerp,  ZCordPerp), // right bottom front
	Vec3(XCordPerp,  YCordPerp,  ZCordPerp), // right top front
	Vec3(XCordPerp,  YCordPerp, -ZCordPerp), // right top back

	// *** FRONT FACE *** //

	// Split it into two parts

	// Triangle 16
	Vec3(XCordPerp,  -YCordPerp,  ZCordPerp), // right bottom front
	Vec3(-XCordPerp,  -YCordPerp,  ZCordPerp), // left bottom front
	Vec3(XCordPerp,   YCordPerp,  ZCordPerp), // right top front

	// Triangle 17
	Vec3(-XCordPerp, -YCordPerp,  ZCordPerp), // left bottom front
	Vec3(-XCordPerp,  YCordPerp,  ZCordPerp), // left top front
	Vec3(XCordPerp,   YCordPerp,  ZCordPerp), // right top front

	// *** LEFT FACE *** //

	// Triangle 18
	Vec3(-XCordPerp, -YCordPerp,  ZCordPerp), // left bottom front
	Vec3(-XCordPerp, -YCordPerp, -ZCordPerp), // left bottom back
	Vec3(-XCordPerp,  YCordPerp,  ZCordPerp), // left top front

	// Triangle 19
	Vec3(-XCordPerp, -YCordPerp, -ZCordPerp), // left bottom back
	Vec3(-XCordPerp,  YCordPerp, -ZCordPerp), // left top back
	Vec3(-XCordPerp,  YCordPerp,  ZCordPerp), // left top front

	// *** BOTTOM FACE *** //

	// Triangle 20
	Vec3(-XCordPerp, -YCordPerp,  ZCordPerp), // left bottom front
	Vec3(XCordPerp, -YCordPerp,   ZCordPerp), // right bottom front
	Vec3(XCordPerp, -YCordPerp,  -ZCordPerp), // right bottom back

	// Triangle 21
	Vec3(XCordPerp, -YCordPerp,  -ZCordPerp), // right bottom back
	Vec3(-XCordPerp, -YCordPerp, -ZCordPerp), // left bottom back
	Vec3(-XCordPerp, -YCordPerp,  ZCordPerp), // left bottom front

	// *** TOP FACE *** //

	// Triangle 21
	Vec3(-XCordPerp,  YCordPerp, -ZCordPerp), // left top back
	Vec3(XCordPerp,  YCordPerp,  -ZCordPerp), // right top back
	Vec3(XCordPerp,  YCordPerp,   ZCordPerp), // right top front

	// Triangle 22
	Vec3(XCordPerp,  YCordPerp,   ZCordPerp), // right top front
	Vec3(-XCordPerp,  YCordPerp,  ZCordPerp), // left top front
	Vec3(-XCordPerp,  YCordPerp, -ZCordPerp),  // left top back

};

VertexTexCoord g_CrossVertices_texCoord[] =
{
	// Triangle 0
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),

	// Triangle 1
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 2
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 3
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 4
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 5
	Vec2f(0.0f, 1.0f),
	Vec2f(0.0f, 0.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 6
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 7
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 8
	Vec2f(0.0f, 0.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(1.0f, 1.0f),

	// Triangle 9
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 10
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 11
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f),

	// *** Perpendicular Cuboid *** //

	// Triangle 0
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),

	// Triangle 1
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 2
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 3
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 4
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 5
	Vec2f(0.0f, 1.0f),
	Vec2f(0.0f, 0.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 6
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 7
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 8
	Vec2f(0.0f, 0.0f),
	Vec2f(1.0f, 0.0f),
	Vec2f(1.0f, 1.0f),

	// Triangle 9
	Vec2f(1.0f, 1.0f),
	Vec2f(0.0f, 1.0f),
	Vec2f(0.0f, 0.0f),

	// Triangle 10
	Vec2f(0.0f, 1.0f),
	Vec2f(1.0f, 1.0f),
	Vec2f(1.0f, 0.0f),

	// Triangle 11
	Vec2f(1.0f, 0.0f),
	Vec2f(0.0f, 0.0f),
	Vec2f(0.0f, 1.0f),

};

VertexNorm g_CrossVertices_norm[] =
{
	// Triangle 0
	Vec3f(-0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(0.6f,  -0.6f, -0.6f),

	// Triangle 1
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f, -0.6f),

	// Triangle 2
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),

	// Triangle 3
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f,  0.6f,  0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),

	// Triangle 4
	Vec3f(0.6f, -0.6f, 0.6f),
	Vec3f(-0.6f, -0.6f, 0.6f),
	Vec3f(0.6f,  0.6f, 0.6f),

	// Triangle 5
	Vec3f(-0.6f, -0.6f, 0.6f),
	Vec3f(-0.6f,  0.6f, 0.6f),
	Vec3f(0.6f,  0.6f, 0.6f),

	// Triangle 6
	Vec3f(-0.6f, -0.6f,  0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f,  0.6f),

	// Triangle 7
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f,  0.6f),

	// Triangle 8
	Vec3f(-0.6f, -0.6f,  0.6f),
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f, -0.6f, -0.6f),

	// Triangle 9
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f,  0.6f),

	// Triangle 10
	Vec3f(-0.6f, 0.6f, -0.6f),
	Vec3f(0.6f, 0.6f, -0.6f),
	Vec3f(0.6f, 0.6f,  0.6f),

	// Triangle 11
	Vec3f(0.6f, 0.6f,  0.6f),
	Vec3f(-0.6f, 0.6f,  0.6f),
	Vec3f(-0.6f, 0.6f, -0.6f),

	// Triangle 0
	Vec3f(-0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(0.6f,  -0.6f, -0.6f),

	// Triangle 1
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f, -0.6f),

	// Triangle 2
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),

	// Triangle 3
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f,  0.6f,  0.6f),
	Vec3f(0.6f,  0.6f, -0.6f),

	// Triangle 4
	Vec3f(0.6f, -0.6f, 0.6f),
	Vec3f(-0.6f, -0.6f, 0.6f),
	Vec3f(0.6f,  0.6f, 0.6f),

	// Triangle 5
	Vec3f(-0.6f, -0.6f, 0.6f),
	Vec3f(-0.6f,  0.6f, 0.6f),
	Vec3f(0.6f,  0.6f, 0.6f),

	// Triangle 6
	Vec3f(-0.6f, -0.6f,  0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f,  0.6f),

	// Triangle 7
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f, -0.6f),
	Vec3f(-0.6f,  0.6f,  0.6f),

	// Triangle 8
	Vec3f(-0.6f, -0.6f,  0.6f),
	Vec3f(0.6f, -0.6f,  0.6f),
	Vec3f(0.6f, -0.6f, -0.6f),

	// Triangle 9
	Vec3f(0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f, -0.6f),
	Vec3f(-0.6f, -0.6f,  0.6f),

	// Triangle 10
	Vec3f(-0.6f, 0.6f, -0.6f),
	Vec3f(0.6f, 0.6f, -0.6f),
	Vec3f(0.6f, 0.6f,  0.6f),

	// Triangle 11
	Vec3f(0.6f, 0.6f,  0.6f),
	Vec3f(-0.6f, 0.6f,  0.6f),
	Vec3f(-0.6f, 0.6f, -0.6f),
};

VertexColor g_CrossVertices_color[] =
{
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 0.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 0.0f) ,
	 Vec3(0.0f, 1.0f, 1.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f) ,
	 Vec3(1.0f, 1.0f, 1.0f) ,
	 Vec3(0.0f, 1.0f, 0.0f) ,
	 Vec3(1.0f, 0.0f, 1.0f)


};


unsigned int NumCrossVerts = sizeof(g_CrossVertices_pos) / sizeof(g_CrossVertices_pos[0]);
unsigned int NumCrossIndices = sizeof(g_CrossIndices) / sizeof(g_CrossIndices[0]);


MeshCross::MeshCross()
	: Mesh(NumCrossVerts, NumCrossIndices),
	VBVBuffer_pos(sizeof(g_CrossVertices_pos), sizeof(VertexPos), g_CrossVertices_pos),
	VBVBuffer_color(sizeof(g_CrossVertices_color), sizeof(VertexColor), g_CrossVertices_color),
	VBVBuffer_tex(sizeof(g_CrossVertices_texCoord), sizeof(VertexTexCoord), g_CrossVertices_texCoord),
	VBVBuffer_norm(sizeof(g_CrossVertices_norm), sizeof(VertexNorm), g_CrossVertices_norm),
	IBVBuffer(sizeof(g_CrossIndices), g_CrossIndices)
{
}

MeshCross::~MeshCross()
{
}

void MeshCross::ActivateMesh()
{
	// ---------------------------------------------
	//    Set (point to ) vertex: position 
	//    Set (point to ) vertex: color
	//    Set (point to ) vertex: texCoord
	//    Set (point ot ) vertex: norm
	// ---------------------------------------------
	this->VBVBuffer_pos.SetActive(VertexSlot::Position);
	this->VBVBuffer_color.SetActive(VertexSlot::Color);
	this->VBVBuffer_tex.SetActive(VertexSlot::TexCoord);
	this->VBVBuffer_norm.SetActive(VertexSlot::Norm);
}

void MeshCross::RenderIndexBuffer()
{
	// ---------------------------------------------
	//    Set (point to ) Index buffer 
	//    Render configuration: Triangles
	// ---------------------------------------------
	this->IBVBuffer.SetActive();
	DirectXDeviceMan::GetContext()->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	//--------------------------------------------------------
	// RENDER - using index data
	//--------------------------------------------------------
	DirectXDeviceMan::GetContext()->DrawIndexed(numIndices, 0, 0);
}

// --- End of File ---
