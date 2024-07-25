//----------------------------------------------------------------------------

//----------------------------------------------------------------------------

#include "StringThis.h"

StringThis::StringThis(Mesh::Name status)
{
	switch(status)
	{
	case Mesh::Name::CUBE:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Mesh::CUBE));
		break;

	case Mesh::Name::PYRAMID:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Mesh::PYRAMID));
		break;

	case Mesh::Name::NOT_INITIALIZED:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Mesh::NOT_INITIALIZED));
		break;

	case Mesh::Name::NULL_MESH:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Mesh::NULL_MESH));
		break;

	default:
		assert(false);
	}
}



StringThis::StringThis(ShaderObject::Name status)
{
	switch(status)
	{
	case ShaderObject::Name::NullShader:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(ShaderObject::NullShader));
		break;

	case ShaderObject::Name::ColorByVertex:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(ShaderObject::ColorByVertex));
		break;

	case ShaderObject::Name::FlatTexture:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(ShaderObject::FlatTexture));
		break;

	case ShaderObject::Name::LightTexture:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(ShaderObject::LightTexture));
		break;

	case ShaderObject::Name::Uninitialized:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(ShaderObject::Uninitialized));
		break;

	default:
		assert(false);
	}
}

StringThis::StringThis(TextureObject::Name status)
{
	switch(status)
	{
	case TextureObject::Name::NullTexture:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(TextureObject::NullShader));
		break;

	case TextureObject::Name::Duckweed:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(TextureObject::Duckweed));
		break;

	case TextureObject::Name::Uninitialized:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(TextureObject::Uninitialized));
		break;

	default:
		assert(false);
	}
}

StringThis::StringThis(Camera::Name status)
{
	switch (status)
	{
	case Camera::Name::BOTTOM:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Camera::BOTTOM));
		break;

	case Camera::Name::TOP:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Camera::TOP));
		break;

	case Camera::Name::CENTER:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Camera::CENTER));
		break;

	case Camera::Name::OPPOSITE:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Camera::OPPOSITE));
		break;

	case Camera::Name::RIGHT:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Camera::RIGHT));
		break;

	case Camera::Name::LEFT:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Camera::LEFT));
		break;

	case Camera::Name::NULL_CAMERA:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Camera::NULL_CAMERA));
		break;

	case Camera::Name::NOT_INITIALIZED:
		strcpy_s(this->buffer, BUFFER_SIZE, STRING_ME(Camera::NOT_INITIALIZED));
		break;

	default:
		assert(false);
	}
}


StringThis::operator char *()
{
	return this->buffer;
}

// --- End of File ---