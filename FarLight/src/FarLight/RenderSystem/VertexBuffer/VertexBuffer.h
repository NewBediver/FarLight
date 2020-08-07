#pragma once

#include "FarLight/RenderSystem/BufferLayout/BufferLayout.h"

namespace FarLight
{
	class VertexBuffer
	{
	public:
		static Ref<VertexBuffer> Create(const void* vertices, unsigned size, const BufferLayout& layout);
		static Ref<VertexBuffer> Create(unsigned size, const BufferLayout& layout);

		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned GetID() const = 0;

		virtual const BufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;

		virtual void AddSubData(const void* vertices, unsigned size) = 0;

		virtual unsigned GetOffset() const = 0;
		virtual void SetOffset(unsigned offset) = 0;

		virtual unsigned GetUsageType() const = 0;
	};
}