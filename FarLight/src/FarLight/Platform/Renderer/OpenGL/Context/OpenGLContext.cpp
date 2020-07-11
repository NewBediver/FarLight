#include "flpch.h"
#include "OpenGLContext.h"

#include "FarLight/Logger.h"

#include <glad/glad.h>

namespace FarLight
{
	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(_windowHandle.get());
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FL_CORE_ASSERT(status, "Failed to initialize Glad!");

		// Comment before tests
		FL_CORE_INFO("===== OpenGL Info =====");
		FL_CORE_INFO("   Vendor: {0}", glGetString(GL_VENDOR));
		FL_CORE_INFO("   Renderer: {0}", glGetString(GL_RENDERER));
		FL_CORE_INFO("   Version: {0}", glGetString(GL_VERSION));
		FL_CORE_INFO("=======================");
	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(_windowHandle.get());
	}
}