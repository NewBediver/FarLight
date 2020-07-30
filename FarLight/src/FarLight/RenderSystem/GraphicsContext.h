#pragma once

namespace FarLight
{
	class GraphicsContext
	{
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() const = 0;

		virtual ~GraphicsContext() = default;
	};
}