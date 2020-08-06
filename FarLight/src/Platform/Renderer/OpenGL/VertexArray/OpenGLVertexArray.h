#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

namespace FarLight
{
	class OpenGLVertexArray
		: public VertexArray
	{
	public:
		explicit OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual unsigned int GetID() const override { return m_RendererID; }

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) override;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }

		virtual ~OpenGLVertexArray();

	private:
		unsigned int m_RendererID;
		unsigned int m_VertexBufferIndex;
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffer;
	};
}