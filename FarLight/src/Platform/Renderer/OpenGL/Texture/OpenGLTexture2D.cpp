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
		glGenTextures(1, &_rendererID);
		glBindTexture(GL_TEXTURE_2D, _rendererID);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);

		if (data)
		{
			_width = width;
			_height = height;
			_channels = channels;

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			FL_CORE_ASSERT(false, "Failed to load texture2D image!");
		}

		stbi_image_free(data);
	}

	void OpenGLTexture2D::Bind(const unsigned int slot) const
	{
		glActiveTexture(slot);
		glBindTexture(GL_TEXTURE_2D, _rendererID);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &_rendererID);
	}
}