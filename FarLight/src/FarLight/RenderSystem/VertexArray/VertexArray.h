#pragma once

#include <memory>

#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"
#include "FarLight/RenderSystem/IndexBuffer/IndexBuffer.h"

namespace FarLight
{
	class VertexArray
	{
	public:
		static Ref<VertexArray> Create() noexcept;

		VertexArray(const VertexArray&) = delete;
		VertexArray(VertexArray&&) = delete;
		VertexArray& operator=(const VertexArray&) = delete;
		VertexArray& operator=(VertexArray&&) = delete;

		explicit VertexArray() noexcept = default;

		virtual ~VertexArray() noexcept = default;

		virtual void Bind() const noexcept = 0;
		virtual void Unbind() const noexcept = 0;

		virtual unsigned GetID() const noexcept = 0;

		virtual void AddVertexBuffer(const Ref<VertexBuffer>& buffer) noexcept = 0;
		virtual void SetIndexBuffer(const Ref<IndexBuffer>& buffer) noexcept = 0;

		virtual const std::vector<Ref<VertexBuffer>>& GetVertexBuffers() const noexcept = 0;
		virtual const Ref<IndexBuffer>& GetIndexBuffer() const noexcept = 0;
	};
}