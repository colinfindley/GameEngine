//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "TextureNode.h"
#include "StringThis.h"

TextureNode::TextureNode()
    : DLink(),
    poTexture(nullptr)
{
    this->privClear();
}

TextureNode::~TextureNode()
{
    this->privClear();
}

void TextureNode::Set(TextureObject::Name name, TextureObject* pTexture)
{
    assert(pTexture);
    this->poTexture = pTexture;

    this->poTexture->SetName(name);
}

TextureObject* TextureNode::GetTexture()
{
    return this->poTexture;
}

void TextureNode::privClear()
{
    if (this->poTexture)
    {
        delete this->poTexture;
    }
    this->poTexture = nullptr;
}

char* TextureNode::GetName()
{
    char* pName = nullptr;
    if (this->poTexture)
    {
        pName = this->poTexture->GetName();
    }

    return pName;
}

void TextureNode::Wash()
{
    this->privClear();
}

bool TextureNode::Compare(DLink* pTargetNode)
{
    // This is used in ManBase.Find() 
    assert(pTargetNode);

    TextureNode* pDataB = (TextureNode*)pTargetNode;

    bool status = false;

    assert(pDataB->poTexture);
    assert(this->poTexture);

    if (this->poTexture->name == pDataB->poTexture->name)
    {
        status = true;
    }

    return status;
}

void TextureNode::Dump()
{
    Trace::out("      TextureNode(%p)\n", this);

    // Data:
    if (this->poTexture)
    {
        Trace::out("      Texture(%p) \n", this->poTexture);
        Trace::out("      Name: %s \n", StringMe(this->poTexture->name));
    }
    else
    {
        Trace::out("      Name: %s \n", "null");
    }

    DLink::Dump();
}

// --- End of File ---
