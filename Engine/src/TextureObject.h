//--------------------------------------------------------------

//--------------------------------------------------------------

#ifndef TEXTURE_OBJECT_H
#define TEXTURE_OBJECT_H

#include <d3d11.h>

class TextureObject
{
public:
	enum class Name
	{
		NullTexture,
		Duckweed,
		Brick,
		Stone,
		Rocks,
		Uninitialized
	};


public:
	TextureObject();
	TextureObject(const TextureObject &) = delete;
	TextureObject &operator = (const TextureObject &) = delete;
	virtual ~TextureObject();

	TextureObject(TextureObject::Name _name, 
		LPCWSTR filepath, 
		D3D11_FILTER filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR, 
		D3D11_TEXTURE_ADDRESS_MODE addressMode = D3D11_TEXTURE_ADDRESS_WRAP);


	virtual void ActivateTexture();

	char *GetName();
	void SetName(TextureObject::Name _name);

	void SetFilter(D3D11_FILTER newFilter);
	void SetAddressMode(D3D11_TEXTURE_ADDRESS_MODE newAddressMode);


	// ---------------------------------------------
	// 	   Data:
	// ---------------------------------------------
	

	ID3D11ShaderResourceView *poTextureRV;
	ID3D11SamplerState *poSampler;


	D3D11_FILTER filter;
	D3D11_TEXTURE_ADDRESS_MODE addressU;
	D3D11_TEXTURE_ADDRESS_MODE addressV;
	D3D11_TEXTURE_ADDRESS_MODE addressW;

	TextureObject::Name name;
	int referenceCount = 0;
protected:
	// New method to create sampler state
	void privCreateSamplerState();

};

#endif

// --- End of File ---
