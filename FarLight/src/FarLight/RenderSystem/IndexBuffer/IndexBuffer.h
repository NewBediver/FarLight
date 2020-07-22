#pragma once

namespace FarLight
{
	class FARLIGHT_API IndexBuffer
	{
	public:
		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual const unsigned int GetCount() const = 0;

		virtual ~IndexBuffer() = default;

		static Ref<IndexBuffer> Create(const unsigned int* indicies, const unsigned int count);
	};
}