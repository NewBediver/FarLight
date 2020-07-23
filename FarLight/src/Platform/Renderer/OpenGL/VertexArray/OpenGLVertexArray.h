#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

namespace FarLight
{
	class OpenGLVertexArray
		: public VertexArray
	{
	public:
		OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) override;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) override;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const { return _vertexBuffers; }
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const { return _indexBuffer; }

		virtual ~OpenGLVertexArray();

	private:
		unsigned int _rendererID;
		unsigned int _vertexBufferIndex;
		std::vector<Ref<VertexBuffer>> _vertexBuffers;
		Ref<IndexBuffer> _indexBuffer;
	};
}