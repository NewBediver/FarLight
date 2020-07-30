#pragma once

#include <vector>

#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

namespace FarLight
{
	class OpenGLIndexBuffer
		: public IndexBuffer
	{
	public:
		explicit OpenGLIndexBuffer(const unsigned int* indicies, unsigned int count);

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual unsigned int GetCount() const override { return m_Count; }

		virtual ~OpenGLIndexBuffer();

	private:
		unsigned int m_RendererID;
		unsigned int m_Count;
	};
}