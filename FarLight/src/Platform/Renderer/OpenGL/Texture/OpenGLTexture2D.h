#pragma once

#include "FarLight/RenderSystem/Texture/Texture2D.h"

#include <glm/glm.hpp>
#include <glad/glad.h>

namespace FarLight
{
	class OpenGLTexture2D
		: public Texture2D
	{
	public:
		explicit OpenGLTexture2D(const std::string& path);
		explicit OpenGLTexture2D(unsigned int width, unsigned int height, const glm::vec4& pixelColor);

		virtual unsigned int GetWidth() const override { return m_Width; }
		virtual unsigned int GetHeight() const override { return m_Height; }

		virtual void Bind(unsigned int slot) const override;
		virtual void Unbind(unsigned int slot) const override;

		virtual void SetData(void* data, unsigned int size) const override;

		virtual ~OpenGLTexture2D();

	private:
		unsigned int m_RendererID;
		unsigned int m_Width, m_Height, m_Channels;
		GLenum m_InternalFormat, m_DataFormat;
	};
}