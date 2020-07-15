#pragma once

#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

namespace FarLight
{
	class FARLIGHT_API OpenGLIndexBuffer
		: public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(unsigned int* indicies, unsigned int count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual unsigned int GetCount() const override { return _count; }

	private:
		unsigned int _rendererID;
		unsigned int _count;
	};
}