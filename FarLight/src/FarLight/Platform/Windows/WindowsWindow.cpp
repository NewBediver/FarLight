#include "flpch.h"
#include "WindowsWindow.h"

#include "FarLight/Core.h"

namespace FarLight
{
	using uint = unsigned int;

	static bool isGLFWInitialized = false;

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	inline uint WindowsWindow::GetWidth() const { return data.width; }
	inline uint WindowsWindow::GetHeight() const { return data.height; }
	inline void WindowsWindow::SetEventCallback(const EventCallbackFunction& callback) { data.callback = callback; }

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) glfwSwapInterval(1);
		else glfwSwapInterval(0);
		data.isVSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return data.isVSync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		data.title = props.title;
		data.height = props.height;
		data.width = props.width;

		// Disable before testing (Arise problems)
		FL_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!isGLFWInitialized)
		{
			int success = glfwInit();
			FL_CORE_ASSERT(success, "Could not initialize GLFW!");
			isGLFWInitialized = true;
		}

		window = glfwCreateWindow(static_cast<int>(props.width), static_cast<int>(props.height), data.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &data);
		SetVSync(true);
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(window);
	}
}
