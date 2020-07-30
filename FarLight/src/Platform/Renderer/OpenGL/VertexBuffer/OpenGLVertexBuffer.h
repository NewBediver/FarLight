#pragma once

#include <vector>

#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"

namespace FarLight
{
	class OpenGLVertexBuffer
		: public VertexBuffer
	{
	public:
		explicit OpenGLVertexBuffer(const float* vertices, unsigned int size, const BufferLayout& layout);

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

		virtual ~OpenGLVertexBuffer();

	private:
		unsigned int m_RendererID;
		BufferLayout m_Layout;
	};
}