#pragma once

#include "FarLight/RenderSystem/BufferLayout/BufferLayout.h"

namespace FarLight
{
	class VertexBuffer
	{
	public:
		static Ref<VertexBuffer> Create(const void* vertices, unsigned size, const BufferLayout& layout) noexcept;
		static Ref<VertexBuffer> Create(unsigned size, const BufferLayout& layout) noexcept;

		VertexBuffer(const VertexBuffer&) = delete;
		VertexBuffer(VertexBuffer&&) = delete;
		VertexBuffer& operator=(const VertexBuffer&) = delete;
		VertexBuffer& operator=(VertexBuffer&&) = delete;

		explicit VertexBuffer() noexcept = default;

		virtual ~VertexBuffer() noexcept = default;

		virtual void Bind() const noexcept = 0;
		virtual void Unbind() const noexcept = 0;

		virtual unsigned GetID() const noexcept = 0;

		virtual const BufferLayout& GetLayout() const noexcept = 0;
		virtual void SetLayout(const BufferLayout& layout) noexcept = 0;

		virtual void AddSubData(const void* vertices, unsigned size) noexcept = 0;

		virtual unsigned GetOffset() const noexcept = 0;
		virtual void SetOffset(unsigned offset) noexcept = 0;

		virtual unsigned GetUsageType() const noexcept = 0;
	};
}