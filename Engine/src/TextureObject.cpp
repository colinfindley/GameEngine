//--------------------------------------------------------------

//--------------------------------------------------------------

#include <Windows.h>
#include <string>
#include <d3d11.h>

#include "TextureObject.h"
#include "Engine.h"
#include "StringThis.h"
#include "DirectXDeviceMan.h"

#include "DirectXTex.h"


using namespace Azul;

TextureObject::TextureObject()
    :
    name(TextureObject::Name::Uninitialized),
    poTextureRV(nullptr),
    poSampler(nullptr),
    filter(D3D11_FILTER_MIN_MAG_MIP_LINEAR),
    addressU(D3D11_TEXTURE_ADDRESS_WRAP),
    addressV(D3D11_TEXTURE_ADDRESS_WRAP),
    addressW(D3D11_TEXTURE_ADDRESS_WRAP)
{
}

TextureObject::~TextureObject()
{
    SafeRelease(poTextureRV);
    SafeRelease(poSampler);
}

TextureObject::TextureObject(TextureObject::Name _name,
    LPCWSTR filepath,
    D3D11_FILTER filter,
    D3D11_TEXTURE_ADDRESS_MODE addressMode)
    :
    name(_name),
    poTextureRV(nullptr),
    poSampler(nullptr),
    filter(filter),
    addressU(addressMode),
    addressV(addressMode),
    addressW(addressMode)
{
    DirectX::ScratchImage testTexture;
    HRESULT hr = LoadFromTGAFile(filepath, nullptr, testTexture);
    assert(SUCCEEDED(hr));

    CreateShaderResourceView(DirectXDeviceMan::GetDevice(),
        testTexture.GetImage(0, 0, 0),
        testTexture.GetImageCount(),
        testTexture.GetMetadata(),
        &poTextureRV);
    assert(this->poTextureRV);

    privCreateSamplerState();
}

void TextureObject::privCreateSamplerState()
{
    // Create the sample state
    D3D11_SAMPLER_DESC sampDesc;
    ZeroMemory(&sampDesc, sizeof(sampDesc));
    sampDesc.Filter = filter;
    sampDesc.AddressU = addressU;
    sampDesc.AddressV = addressV;
    sampDesc.AddressW = addressW;
    sampDesc.ComparisonFunc = D3D11_COMPARISON_NEVER;
    sampDesc.MinLOD = 0;
    sampDesc.MaxLOD = D3D11_FLOAT32_MAX;

    SafeRelease(poSampler);
    HRESULT hr = DirectXDeviceMan::GetDevice()->CreateSamplerState(&sampDesc, &poSampler);
    assert(SUCCEEDED(hr));
    assert(this->poSampler);
}

void TextureObject::ActivateTexture()
{
    DirectXDeviceMan::GetContext()->PSSetShaderResources((uint32_t)ShaderResourceBufferSlot::TexA, 1, &poTextureRV);
    DirectXDeviceMan::GetContext()->PSSetSamplers((uint32_t)ShaderSamplerSlot::SampleA, 1, &poSampler);
}

void TextureObject::SetName(TextureObject::Name _name)
{
    this->name = _name;
}

char* TextureObject::GetName()
{
    // todo - Hack understand why is this needed for print and fix...
    static char pTmp[128];
    strcpy_s(pTmp, 128, StringMe(this->name));
    return pTmp;
}

void TextureObject::SetFilter(D3D11_FILTER newFilter)
{
    this->filter = newFilter;
    privCreateSamplerState();
}

void TextureObject::SetAddressMode(D3D11_TEXTURE_ADDRESS_MODE newAddressMode)
{
    this->addressU = newAddressMode;
    this->addressV = newAddressMode;
    this->addressW = newAddressMode;
    privCreateSamplerState();
}
