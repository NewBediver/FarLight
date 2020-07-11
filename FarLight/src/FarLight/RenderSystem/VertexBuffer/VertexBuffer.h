#pragma once

namespace FarLight
{
	class FARLIGHT_API VertexBuffer
	{
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static std::unique_ptr<VertexBuffer> Create(float* vetricies, unsigned int size);
	};
}