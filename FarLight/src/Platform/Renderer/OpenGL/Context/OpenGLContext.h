#pragma once

#include "FarLight/RenderSystem/GraphicsContext.h"

#include <GLFW\glfw3.h>

namespace FarLight
{
	class OpenGLContext final
		: public GraphicsContext
	{
	public:
		explicit OpenGLContext(const Ref<GLFWwindow>& windowHandle)
			: m_WindowHandle(windowHandle)
		{ }

		virtual void Init() override;
		virtual void SwapBuffers() const override;

	private:
		Ref<GLFWwindow> m_WindowHandle;
	};
}