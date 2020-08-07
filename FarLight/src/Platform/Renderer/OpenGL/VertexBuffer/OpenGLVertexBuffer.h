#pragma once

#include <vector>

#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"

#include <glad/glad.h>

namespace FarLight
{
	class OpenGLVertexBuffer
		: public VertexBuffer
	{
	public:
		explicit OpenGLVertexBuffer(const void* vertices, unsigned size, const BufferLayout& layout);
		explicit OpenGLVertexBuffer(unsigned size, const BufferLayout& layout);

		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual unsigned GetID() const override { return m_RendererID; }

		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

		virtual unsigned GetOffset() const override { return m_Offset; }
		virtual void SetOffset(unsigned offset) override { m_Offset = offset; }

		virtual unsigned GetUsageType() const override { return m_UsageType; }

		virtual void AddSubData(const void* vertices, unsigned size) override;

	private:
		unsigned m_RendererID;
		unsigned m_Offset;
		BufferLayout m_Layout;
		GLenum m_UsageType;
	};
}