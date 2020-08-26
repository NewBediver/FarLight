#pragma once

namespace FarLight
{
	class IndexBuffer
	{
	public:
		static Ref<IndexBuffer> Create(const void* indicies, unsigned count) noexcept;
		static Ref<IndexBuffer> Create(unsigned count) noexcept;

		virtual ~IndexBuffer() noexcept = default;

		virtual void Bind() const noexcept = 0;
		virtual void Unbind() const noexcept = 0;

		virtual unsigned GetID() const noexcept = 0;

		virtual unsigned GetUsageType() const noexcept = 0;

		virtual unsigned GetCount() const noexcept = 0;
		virtual void SetCount(unsigned count) noexcept = 0;

		virtual void AddSubData(const void* indices, unsigned count) noexcept = 0;
	};
}