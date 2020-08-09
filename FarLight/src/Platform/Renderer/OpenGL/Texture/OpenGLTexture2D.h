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
		OpenGLTexture2D(const OpenGLTexture2D&) = delete;
		OpenGLTexture2D(OpenGLTexture2D&&) = delete;
		OpenGLTexture2D& operator=(const OpenGLTexture2D&) = delete;
		OpenGLTexture2D& operator=(OpenGLTexture2D&&) = delete;

		explicit OpenGLTexture2D(const std::string& path) noexcept;
		explicit OpenGLTexture2D(unsigned width, unsigned height, const glm::vec4& pixelColor) noexcept;

		virtual ~OpenGLTexture2D() noexcept;

		virtual void Bind(unsigned slot) const noexcept override;
		virtual void Unbind(unsigned slot) const noexcept override;

		virtual unsigned GetID() const noexcept override { return m_RendererID; }

		virtual unsigned GetWidth() const noexcept override { return m_Width; }
		virtual unsigned GetHeight() const noexcept override { return m_Height; }

		virtual void SetData(const void* data, unsigned size) const noexcept override;

	private:
		unsigned m_RendererID;
		unsigned m_Width, m_Height, m_Channels;
		GLenum m_InternalFormat, m_DataFormat;
	};
}