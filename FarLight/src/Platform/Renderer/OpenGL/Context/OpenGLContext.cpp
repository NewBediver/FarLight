// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLContext.h"
#include "FarLight/LogSystem/Logger.h"

#include <glad/glad.h>

namespace FarLight
{
	void OpenGLContext::Init()
	{
		FL_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle.get());
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FL_CORE_ASSERT(status, "Failed to initialize Glad!");

		int versionMajor;
		int versionMinor;
		glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
		glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

		FL_CORE_INFO("==================== OpenGL Info ====================");
		FL_CORE_INFO("   GPU Vendor: {0}", glGetString(GL_VENDOR));
		FL_CORE_INFO("   GPU Renderer: {0}", glGetString(GL_RENDERER));
		FL_CORE_INFO("   GPU Version: {0}", glGetString(GL_VERSION));
		FL_CORE_INFO("   OpenGL Version: {0}.{1}", versionMajor, versionMinor);
		FL_CORE_INFO("=====================================================");

		#ifdef FL_ENABLE_ASSERTS
			FL_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "FarLight requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers() const
	{
		FL_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle.get());
	}
}