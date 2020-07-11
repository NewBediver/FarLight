#pragma once

namespace FarLight
{
	class FARLIGHT_API IndexBuffer
	{
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual unsigned int GetCount() const = 0;

		static std::unique_ptr<IndexBuffer> Create(unsigned int* indicies, unsigned int count);
	};
}