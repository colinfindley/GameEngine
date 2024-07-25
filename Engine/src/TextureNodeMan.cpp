//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "TextureNodeMan.h"
#include "TextureNull.h"
#include "ManBase.h"
#include "DLinkMan.h"

TextureNodeMan* TextureNodeMan::posInstance = nullptr;

//----------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------
TextureNodeMan::TextureNodeMan(int reserveNum, int reserveGrow)
	: ManBase(new DLinkMan(), new DLinkMan(), reserveNum, reserveGrow)
{
	// Preload the reserve
	this->proFillReservedPool(reserveNum);

	// -----------------------
	// Compare Node create
	// -----------------------
	TextureObject* pTexture = new TextureNull();
	assert(pTexture);
	this->poNodeCompare = new TextureNode();
	assert(this->poNodeCompare);
	this->poNodeCompare->Set(TextureObject::Name::NullTexture, pTexture);
}

TextureNodeMan::~TextureNodeMan()
{
	delete this->poNodeCompare;
	this->poNodeCompare = nullptr;

	// iterate through the list and delete
	Iterator* pIt = this->baseGetActiveIterator();

	DLink* pNode = pIt->First();

	// Walk through the nodes
	while (!pIt->IsDone())
	{
		TextureNode* pDeleteMe = (TextureNode*)pIt->Curr();
		pNode = pIt->Next();
		delete pDeleteMe;
	}

	pIt = this->baseGetReserveIterator();

	pNode = pIt->First();

	// Walk through the nodes
	while (!pIt->IsDone())
	{
		TextureNode* pDeleteMe = (TextureNode*)pIt->Curr();
		pNode = pIt->Next();
		delete pDeleteMe;
	}
}

//----------------------------------------------------------------------
// Static Methods
//----------------------------------------------------------------------
void TextureNodeMan::Create(int reserveNum, int reserveGrow)
{
	// make sure values are ressonable 
	assert(reserveNum >= 0);
	assert(reserveGrow > 0);

	// initialize the singleton here
	assert(posInstance == nullptr);

	// Do the initialization
	if (posInstance == nullptr)
	{
		posInstance = new TextureNodeMan(reserveNum, reserveGrow);
	}
}

void TextureNodeMan::Destroy()
{
	TextureNodeMan* pMan = TextureNodeMan::privGetInstance();
	assert(pMan != nullptr);
	AZUL_UNUSED_VAR(pMan);

	delete TextureNodeMan::posInstance;
	TextureNodeMan::posInstance = nullptr;
}

TextureNode* TextureNodeMan::Add(TextureObject::Name name, TextureObject* pTexture)
{
	TextureNodeMan* pMan = TextureNodeMan::privGetInstance();

	assert(pTexture);

	TextureNode* pNode = (TextureNode*)pMan->baseAddToFront();
	assert(pNode != nullptr);

	// Initialize the date
	pNode->Set(name, pTexture);

	return pNode;
}

TextureNode* TextureNodeMan::Find(TextureObject::Name _name)
{
	TextureNodeMan* pMan = TextureNodeMan::privGetInstance();
	assert(pMan != nullptr);

	// Compare functions only compares two Nodes

	// So:  Use the Compare Node - as a reference
	//      use in the Compare() function
	TextureObject* pTexture = pMan->poNodeCompare->GetTexture();
	assert(pTexture);

	pTexture->name = _name;

	TextureNode* pData = (TextureNode*)pMan->baseFind(pMan->poNodeCompare);
	return pData;
}

void TextureNodeMan::Remove(TextureNode* pNode)
{
	assert(pNode != nullptr);

	TextureNodeMan* pMan = TextureNodeMan::privGetInstance();
	assert(pMan != nullptr);

	pMan->baseRemove(pNode);
}

void TextureNodeMan::Dump()
{
	TextureNodeMan* pMan = TextureNodeMan::privGetInstance();
	assert(pMan != nullptr);

	pMan->baseDump();
}

//----------------------------------------------------------------------
// Private methods
//----------------------------------------------------------------------
TextureNodeMan* TextureNodeMan::privGetInstance()
{
	// Safety - this forces users to call Create() first before using class
	assert(posInstance != nullptr);

	return posInstance;
}

//----------------------------------------------------------------------
// Override Abstract methods
//----------------------------------------------------------------------
DLink* TextureNodeMan::derivedCreateNode()
{
	DLink* pNodeBase = new TextureNode();
	assert(pNodeBase != nullptr);

	return pNodeBase;
}

// --- End of File ---
