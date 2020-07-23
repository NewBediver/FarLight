#pragma once

#include "FarLight/RenderSystem/Texture/Texture2D.h"

namespace FarLight
{
	class FARLIGHT_API OpenGLTexture2D
		: public Texture2D
	{
	public:
		explicit OpenGLTexture2D(const std::string& path);

		virtual const unsigned int GetWidth() const override { return _width; }
		virtual const unsigned int GetHeight() const override { return _height; }
		virtual void Bind(const unsigned int slot) const override;

		virtual ~OpenGLTexture2D();

	private:
		unsigned int _width, _height, _channels;
		unsigned int _rendererID;
	};
}