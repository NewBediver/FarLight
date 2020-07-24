// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLTexture2D.h"

#include <stb_image.h>
#include <glad/glad.h>

namespace FarLight
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		: _width(0), _height(0), _channels(0), _rendererID(0)
	{
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);

		FL_CORE_ASSERT(data, "Failed to load texture2D image!");

		GLenum internalFormat = 0, dataFormat = 0;
		switch (channels)
		{
			case 1:
			{
				internalFormat = GL_R8;
				dataFormat = GL_R;
				break;
			}
			case 2:
			{
				internalFormat = GL_RG8;
				dataFormat = GL_RG;
				break;
			}
			case 3:
			{
				internalFormat = GL_RGB8;
				dataFormat = GL_RGB;
				break;
			}
			case 4:
			{
				internalFormat = GL_RGBA8;
				dataFormat = GL_RGBA;
				break;
			}
		}

		FL_CORE_ASSERT(internalFormat && dataFormat, "Texture format is not supported!");

		_width = width;
		_height = height;
		_channels = channels;

		glCreateTextures(GL_TEXTURE_2D, 1, &_rendererID);
		glTextureStorage2D(_rendererID, 1, internalFormat, _width, _height);

		glTextureParameteri(_rendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_rendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureSubImage2D(_rendererID, 0, 0, 0, _width, _height, dataFormat, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}

	void OpenGLTexture2D::Bind(const unsigned int slot) const
	{
		glBindTextureUnit(slot, _rendererID);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &_rendererID);
	}
}