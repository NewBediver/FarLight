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
		explicit OpenGLVertexBuffer(const float* vertices, unsigned int size, const BufferLayout& layout);
		explicit OpenGLVertexBuffer(unsigned int size, const BufferLayout& layout);

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual unsigned int GetID() const override { return m_RendererID; }

		virtual const BufferLayout& GetLayout() const override { return m_Layout; }
		virtual void SetLayout(const BufferLayout& layout) override { m_Layout = layout; }

		virtual unsigned int GetOffset() const override { return m_Offset; }
		virtual void SetOffset(unsigned int offset) override { m_Offset = offset; }

		virtual unsigned int GetUsageType() const override { return m_UsageType; }

		virtual void AddSubData(const float* vertices, unsigned int size) override;

		virtual ~OpenGLVertexBuffer();

	private:
		unsigned int m_RendererID;
		unsigned int m_Offset;
		BufferLayout m_Layout;
		GLenum m_UsageType;
	};
}