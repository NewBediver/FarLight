#pragma once

#include "FarLight/RenderSystem/GraphicsContext.h"

#include <GLFW\glfw3.h>

namespace FarLight
{
	class FARLIGHT_API OpenGLContext
		: public GraphicsContext
	{
	public:
		OpenGLContext(std::shared_ptr<GLFWwindow> windowHandle)
			: _windowHandle(windowHandle) { }

		virtual void Init() override;
		virtual void SwapBuffers() override;

	private:
		std::shared_ptr<GLFWwindow> _windowHandle;
	};
}