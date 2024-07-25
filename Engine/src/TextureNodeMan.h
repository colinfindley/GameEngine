//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef TEXTURE_OBJECT_MAN_H
#define TEXTURE_OBJECT_MAN_H

#include "ManBase.h"
#include "TextureNode.h"
#include "TextureObject.h"

class TextureNodeMan : public ManBase
{
	//----------------------------------------------------------------------
	// Static Methods
	//----------------------------------------------------------------------
public:
	static void Create(int reserveNum = 0, int reserveGrow = 1);
	static void Destroy();

	static TextureNode* Add(TextureObject::Name name, TextureObject* pTex);
	static TextureNode* Find(TextureObject::Name name);

	static void Remove(TextureNode* pNode);
	static void Dump();

	//----------------------------------------------------------------------
	// Private methods
	//----------------------------------------------------------------------
private:
	static TextureNodeMan* privGetInstance();

	~TextureNodeMan();
	TextureNodeMan(int reserveNum, int reserveGrow);

	//----------------------------------------------------------------------
	// Override Abstract methods
	//----------------------------------------------------------------------
protected:
	DLink* derivedCreateNode() override;

	//----------------------------------------------------------------------
	// Data: unique data for this manager 
	//----------------------------------------------------------------------
private:
	TextureNode* poNodeCompare;
	static TextureNodeMan* posInstance;
};

#endif

// --- End of File ---
