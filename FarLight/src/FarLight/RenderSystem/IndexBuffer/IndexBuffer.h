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

		virtual ~IndexBuffer() = default;

		static Ref<IndexBuffer> Create(const unsigned int* indicies, unsigned int count);
	};
}