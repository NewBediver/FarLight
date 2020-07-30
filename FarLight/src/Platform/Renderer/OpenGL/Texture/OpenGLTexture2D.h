#pragma once

#include "FarLight/RenderSystem/Texture/Texture2D.h"

namespace FarLight
{
	class OpenGLTexture2D
		: public Texture2D
	{
	public:
		explicit OpenGLTexture2D(const std::string& path);

		virtual unsigned int GetWidth() const override { return m_Width; }
		virtual unsigned int GetHeight() const override { return m_Height; }
		virtual void Bind(unsigned int slot) const override;

		virtual ~OpenGLTexture2D();

	private:
		unsigned int m_Width, m_Height, m_Channels;
		unsigned int m_RendererID;
	};
}