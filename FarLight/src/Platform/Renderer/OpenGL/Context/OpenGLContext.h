#pragma once

#include "FarLight/RenderSystem/GraphicsContext.h"

#include <GLFW\glfw3.h>

namespace FarLight
{
	class FARLIGHT_API OpenGLContext
		: public GraphicsContext
	{
	public:
		OpenGLContext(const Ref<GLFWwindow>& windowHandle)
			: _windowHandle(windowHandle) { }

		virtual void Init() override;
		virtual void SwapBuffers() const override;

	private:
		Ref<GLFWwindow> _windowHandle;
	};
}