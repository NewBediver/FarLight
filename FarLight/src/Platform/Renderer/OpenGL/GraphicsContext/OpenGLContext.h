#pragma once

#include "FarLight/RenderSystem/GraphicsContext/GraphicsContext.h"

#include <GLFW\glfw3.h>

namespace FarLight
{
	class OpenGLContext final
		: public GraphicsContext
	{
	public:
		explicit OpenGLContext(const Ref<GLFWwindow>& windowHandle) noexcept
			: m_WindowHandle(windowHandle)
		{ }

		virtual void Init() const noexcept override;
		virtual void SwapBuffers() const noexcept override;

	private:
		Ref<GLFWwindow> m_WindowHandle;
	};
}