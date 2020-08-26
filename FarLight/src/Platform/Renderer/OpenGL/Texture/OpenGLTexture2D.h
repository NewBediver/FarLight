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
		explicit OpenGLTexture2D(const std::string& path) noexcept;
		explicit OpenGLTexture2D(unsigned width, unsigned height, const glm::vec4& pixelColor) noexcept;

		virtual ~OpenGLTexture2D() noexcept;

		virtual void Bind(unsigned slot) const noexcept override;
		virtual void Unbind(unsigned slot) const noexcept override;

		virtual unsigned GetID() const noexcept override { return m_RendererID; }

		virtual unsigned GetWidth() const noexcept override { return m_Width; }
		virtual unsigned GetHeight() const noexcept override { return m_Height; }

		virtual const std::array<glm::vec2, 4>& GetCoordinates() const noexcept override { return m_Coordinates; }
		virtual const glm::vec2& GetLowerLeftCoordinate() const noexcept override { return m_Coordinates[0]; }
		virtual const glm::vec2& GetLowerRightCoordinate() const noexcept override { return m_Coordinates[1]; }
		virtual const glm::vec2& GetUpperRightCoordinate() const noexcept override { return m_Coordinates[2]; }
		virtual const glm::vec2& GetUpperLeftCoordinate() const noexcept override { return m_Coordinates[3]; }

		virtual void SetData(const void* data, unsigned size) const noexcept override;

	private:
		unsigned m_RendererID;
		unsigned m_Width, m_Height, m_Channels;
		std::array<glm::vec2, 4> m_Coordinates;
		GLenum m_InternalFormat, m_DataFormat;
	};
}