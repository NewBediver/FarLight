#pragma once

#include <memory>

#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

namespace FarLight
{
	class VertexArray
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned int GetID() const = 0;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) = 0;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) = 0;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const = 0;

		virtual ~VertexArray() = default;

		static Ref<VertexArray> Create();
	};
}