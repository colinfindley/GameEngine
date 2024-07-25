//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#ifndef Texture_NULL_H
#define Texture_NULL_H

#include "TextureObject.h"

class TextureNull : public TextureObject
{
public:
	TextureNull();
	TextureNull(const TextureNull&) = delete;
	TextureNull& operator=(const TextureNull& other) = delete;
	virtual ~TextureNull();

	virtual void ActivateTexture() override;

private:

};

#endif

// --- End of File ---
