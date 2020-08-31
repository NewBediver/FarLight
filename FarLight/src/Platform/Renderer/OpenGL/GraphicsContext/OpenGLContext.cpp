// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLContext.h"

#include <glad/glad.h>

namespace FarLight
{
	void OpenGLContext::Init() const noexcept
	{
		FL_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle.get());
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FL_CORE_ASSERT(status, "Failed to initialize Glad!");

		FL_CORE_INFO("==================== OpenGL Info ====================");
		FL_CORE_INFO("   GPU Vendor: {0}", glGetString(GL_VENDOR));
		FL_CORE_INFO("   GPU Renderer: {0}", glGetString(GL_RENDERER));
		FL_CORE_INFO("   GPU Version: {0}", glGetString(GL_VERSION));
		FL_CORE_INFO("   OpenGL Version: {0}.{1}", GLVersion.major, GLVersion.minor);
		FL_CORE_INFO("=====================================================");

		#ifdef FL_ENABLE_ASSERTS
			FL_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "FarLight requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers() const noexcept
	{
		FL_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle.get());
	}
}
