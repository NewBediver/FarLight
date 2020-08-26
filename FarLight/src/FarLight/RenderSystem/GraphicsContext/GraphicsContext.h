#pragma once

namespace FarLight
{
	class GraphicsContext
	{
	public:
		virtual ~GraphicsContext() noexcept = default;

		virtual void Init() const noexcept = 0;
		virtual void SwapBuffers() const noexcept = 0;
	};
}