#pragma once

namespace FarLight
{
	class GraphicsContext
	{
	public:
		GraphicsContext(const GraphicsContext&) = delete;
		GraphicsContext(GraphicsContext&&) = delete;
		GraphicsContext& operator=(const GraphicsContext&) = delete;
		GraphicsContext& operator=(GraphicsContext&&) = delete;

		explicit GraphicsContext() noexcept = default;

		virtual ~GraphicsContext() noexcept = default;

		virtual void Init() const noexcept = 0;
		virtual void SwapBuffers() const noexcept = 0;
	};
}