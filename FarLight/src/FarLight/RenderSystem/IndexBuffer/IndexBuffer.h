#pragma once

#include <vector>

namespace FarLight
{
	class IndexBuffer
	{
	public:
		static Ref<IndexBuffer> Create(const void* indicies, unsigned count);
		static Ref<IndexBuffer> Create(unsigned count);

		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned GetID() const = 0;

		virtual unsigned GetUsageType() const = 0;

		virtual unsigned GetCount() const = 0;
		virtual void SetCount(unsigned count) = 0;

		virtual void AddSubData(const void* indices, unsigned size) = 0;
	};
}