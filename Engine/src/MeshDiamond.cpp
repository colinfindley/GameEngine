#include "MeshDiamond.h"

//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "MeshDiamond.h"
#include "MathEngine.h"
#include "DirectXDeviceMan.h"
#include "ShaderMappings.h"

using namespace Azul;

// Vertex positions (scaled down by a factor of 0.5)
VertexPos g_DiamondVertices_pos[] = {
    Vec3(0.0f, 0.5f, 0.0f),    // 0 Top vertex
    Vec3(-0.25f, 0.0f, -0.25f), // 1
    Vec3(0.25f, 0.0f, -0.25f),  // 2
    Vec3(0.25f, 0.0f, 0.25f),   // 3
    Vec3(-0.25f, 0.0f, 0.25f),  // 4
    Vec3(0.0f, -0.5f, 0.0f)    // 5 Bottom vertex
};

// Vertex colors
VertexColor g_DiamondVertices_color[] = {
    Vec3(1.0f, 0.0f, 0.0f), // Top vertex red
    Vec3(0.0f, 1.0f, 0.0f), // Green
    Vec3(0.0f, 0.0f, 1.0f), // Blue
    Vec3(1.0f, 1.0f, 0.0f), // Yellow
    Vec3(1.0f, 0.0f, 1.0f), // Magenta
    Vec3(0.0f, 1.0f, 1.0f)  // Bottom vertex cyan
};

// Indices
uint32_t g_DiamondIndices[] = {
    0, 1, 2, // Top front face
    0, 2, 3, // Top right face
    0, 3, 4, // Top back face
    0, 4, 1, // Top left face
    5, 2, 1, // Bottom front face
    5, 3, 2, // Bottom right face
    5, 4, 3, // Bottom back face
    5, 1, 4  // Bottom left face
};

// Texture coordinates
VertexTexCoord g_DiamondVertices_texCoord[] = {
    Vec2f(0.5f, 1.0f), // Top vertex
    Vec2f(0.0f, 0.5f), // Middle vertices
    Vec2f(1.0f, 0.5f),
    Vec2f(1.0f, 0.0f),
    Vec2f(0.0f, 0.0f),
    Vec2f(0.5f, 0.0f)  // Bottom vertex
};

// Normal vectors
VertexNorm g_DiamondVertices_norm[] = {
    Vec3f(0.0f, 1.0f, 0.0f),  // Top vertex
    Vec3f(-1.0f, 0.0f, -1.0f),// Middle vertices
    Vec3f(1.0f, 0.0f, -1.0f),
    Vec3f(1.0f, 0.0f, 1.0f),
    Vec3f(-1.0f, 0.0f, 1.0f),
    Vec3f(0.0f, -1.0f, 0.0f)  // Bottom vertex
};

unsigned int NumDiamondVerts = sizeof(g_DiamondVertices_pos) / sizeof(g_DiamondVertices_pos[0]);
unsigned int NumDiamondIndices = sizeof(g_DiamondIndices) / sizeof(g_DiamondIndices[0]);


MeshDiamond::MeshDiamond()
	: Mesh(NumDiamondVerts, NumDiamondIndices),
	VBVBuffer_pos(sizeof(g_DiamondVertices_pos), sizeof(VertexPos), g_DiamondVertices_pos),
	VBVBuffer_color(sizeof(g_DiamondVertices_color), sizeof(VertexColor), g_DiamondVertices_color),
	VBVBuffer_tex(sizeof(g_DiamondVertices_texCoord), sizeof(VertexTexCoord), g_DiamondVertices_texCoord),
	VBVBuffer_norm(sizeof(g_DiamondVertices_norm), sizeof(VertexNorm), g_DiamondVertices_norm),
	IBVBuffer(sizeof(g_DiamondIndices), g_DiamondIndices)
{
}

MeshDiamond::~MeshDiamond()
{
}

void MeshDiamond::ActivateMesh()
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

void MeshDiamond::RenderIndexBuffer()
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
