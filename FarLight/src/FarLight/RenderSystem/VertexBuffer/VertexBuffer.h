#pragma once

#include "FarLight/RenderSystem/BufferLayout/BufferLayout.h"

namespace FarLight
{
	class VertexBuffer
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned int GetID() const = 0;

		virtual const BufferLayout& GetLayout() const = 0;
		virtual void SetLayout(const BufferLayout& layout) = 0;

		virtual void AddSubData(const float* vertices, unsigned int size) = 0;

		virtual unsigned int GetOffset() const = 0;
		virtual void SetOffset(unsigned int offset) = 0;

		virtual unsigned int GetUsageType() const = 0;

		virtual ~VertexBuffer() = default;

		static Ref<VertexBuffer> Create(const float* vertices, unsigned int size, const BufferLayout& layout);
		static Ref<VertexBuffer> Create(unsigned int size, const BufferLayout& layout);
	};
}