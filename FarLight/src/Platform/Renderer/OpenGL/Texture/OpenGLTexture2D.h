#pragma once

#include "FarLight/RenderSystem/Texture/Texture2D.h"

#include <glm/glm.hpp>
#include <glad/glad.h>

namespace FarLight
{
	class OpenGLTexture2D final
		: public Texture2D
	{
	public:
		explicit OpenGLTexture2D(const std::string& path);
		explicit OpenGLTexture2D(unsigned width, unsigned height, const glm::vec4& pixelColor);

		virtual ~OpenGLTexture2D();

		virtual void Bind(unsigned slot) const override;
		virtual void Unbind(unsigned slot) const override;

		virtual unsigned GetID() const override { return m_RendererID; }

		virtual unsigned GetWidth() const override { return m_Width; }
		virtual unsigned GetHeight() const override { return m_Height; }

		virtual void SetData(const void* data, unsigned size) const override;

	private:
		unsigned m_RendererID;
		unsigned m_Width, m_Height, m_Channels;
		GLenum m_InternalFormat, m_DataFormat;
	};
}