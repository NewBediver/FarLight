// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLTexture2D.h"

#include <stb_image.h>

namespace FarLight
{
	OpenGLTexture2D::OpenGLTexture2D(const std::string& path)
		: m_RendererID(0)
		, m_Width(0)
		, m_Height(0)
		, m_Channels(0)
		, m_InternalFormat(0)
		, m_DataFormat(0)
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

		FL_CORE_ASSERT(internalFormat & dataFormat, "Texture format is not supported!");

		m_Width = width;
		m_Height = height;
		m_Channels = channels;
		m_InternalFormat = internalFormat;
		m_DataFormat = dataFormat;

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, m_InternalFormat, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		SetData(data, sizeof(data));

		stbi_image_free(data);
	}

	OpenGLTexture2D::OpenGLTexture2D(unsigned int width, unsigned int height, const glm::vec4& pixelColor)
		: m_RendererID(0)
		, m_Width(width)
		, m_Height(height)
		, m_Channels(4)
		, m_InternalFormat(GL_RGBA8)
		, m_DataFormat(GL_RGBA)
	{
		FL_CORE_ASSERT(m_Width > 0 && m_Height > 0, "Wrong Texture2D dimensions!");

		glCreateTextures(GL_TEXTURE_2D, 1, &m_RendererID);
		glTextureStorage2D(m_RendererID, 1, m_InternalFormat, m_Width, m_Height);

		glTextureParameteri(m_RendererID, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(m_RendererID, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		unsigned int color = static_cast<unsigned int>(pixelColor.r * 255.0f)
			+ (static_cast<unsigned int>(pixelColor.g * 255.0f) << 8)
			+ (static_cast<unsigned int>(pixelColor.b * 255.0f) << 16)
			+ (static_cast<unsigned int>(pixelColor.a * 255.0f) << 24);
		std::vector<unsigned int> colors(width * height, color);

		SetData(&colors.front(), sizeof(color) * m_Width * m_Height);
	}

	void OpenGLTexture2D::Bind(unsigned int slot) const
	{
		glBindTextureUnit(slot, m_RendererID);
	}

	void OpenGLTexture2D::Unbind(unsigned int slot) const
	{
		glBindTextureUnit(slot, 0);
	}

	void OpenGLTexture2D::SetData(void* data, unsigned int size) const
	{
		glTextureSubImage2D(m_RendererID, 0, 0, 0, m_Width, m_Height, m_DataFormat, GL_UNSIGNED_BYTE, data);
	}

	OpenGLTexture2D::~OpenGLTexture2D()
	{
		glDeleteTextures(1, &m_RendererID);
	}
}