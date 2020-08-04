#pragma once

#include <vector>

namespace FarLight
{
	class IndexBuffer
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned int GetCount() const = 0;
		virtual void SetCount(unsigned int count) = 0;

		virtual void AddSubData(const unsigned int* vertices, unsigned int size, unsigned int offset) = 0;

		virtual ~IndexBuffer() = default;

		static Ref<IndexBuffer> Create(const unsigned int* indicies, unsigned int count);
		static Ref<IndexBuffer> Create(unsigned int count);
	};
}