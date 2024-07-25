//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef Texture_NODE_H
#define Texture_NODE_H

#include "DLink.h"
#include "TextureObject.h"

class TextureNode : public DLink
{
public:
	TextureNode();
	TextureNode(const TextureObject&) = delete;
	TextureNode& operator = (const TextureObject&) = delete;
	virtual ~TextureNode();

	void Set(TextureObject::Name name, TextureObject* pTexture);
	TextureObject* GetTexture();

	virtual char* GetName() override;
	virtual void Wash() override;
	virtual bool Compare(DLink* pTargetNode) override;
	virtual void Dump() override;

private:
	void privClear();

	//--------------------------------------------------
	// Data
	//--------------------------------------------------
	TextureObject* poTexture;
};

#endif

// --- End of File ---
