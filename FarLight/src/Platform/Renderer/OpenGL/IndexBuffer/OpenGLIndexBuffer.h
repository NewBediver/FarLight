#pragma once

#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

namespace FarLight
{
	class FARLIGHT_API OpenGLIndexBuffer
		: public IndexBuffer
	{
	public:
		OpenGLIndexBuffer(const unsigned int* indicies, const unsigned int count);

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const unsigned int GetCount() const override { return _count; }

		virtual ~OpenGLIndexBuffer();

	private:
		unsigned int _rendererID;
		unsigned int _count;
	};
}