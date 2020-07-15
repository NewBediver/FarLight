#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

namespace FarLight
{
	class OpenGLVertexArray
		: public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& buffer) override;
		virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer>& buffer) override;

		virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return _vertexBuffers; }
		virtual const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return _indexBuffer; }

	private:
		unsigned int _rendererID;
		std::vector<std::shared_ptr<VertexBuffer>> _vertexBuffers;
		std::shared_ptr<IndexBuffer> _indexBuffer;
	};
}