#include "flpch.h"
#include "WindowsWindow.h"

#include "FarLight/EventSystem/WindowEvents/WindowResizedEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowClosedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyPressedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyReleasedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseButtonPressedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseButtonReleasedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseMovedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseScrolledEvent.h"

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

		SetGLFWCallbacks();
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(window);
	}

	void WindowsWindow::SetGLFWCallbacks()
	{
		#define GET_DATA(x) *static_cast<WindowData*>(glfwGetWindowUserPointer(x));

		glfwSetWindowSizeCallback(window, [](GLFWwindow* win, int width, int height) {
			WindowData& data = GET_DATA(win);
			data.width = width;
			data.height = height;
			
			data.callback(WindowResizedEvent(width, height));
		});

		glfwSetWindowCloseCallback(window, [](GLFWwindow* win) {
			WindowData& data = GET_DATA(win);

			data.callback(WindowClosedEvent());
		});

		glfwSetKeyCallback(window, [](GLFWwindow* win, int key, int scan, int action, int mods) {
			WindowData& data = GET_DATA(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					data.callback(KeyboardKeyPressedEvent(key, 0));
					break;
				}
				case GLFW_RELEASE:
				{
					data.callback(KeyboardKeyReleasedEvent(key));
					break;
				}
				case GLFW_REPEAT:
				{
					data.callback(KeyboardKeyPressedEvent(key, 1));
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* win, int button, int action, int mods) {
			WindowData& data = GET_DATA(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					data.callback(MouseButtonPressedEvent(button));
					break;
				}
				case GLFW_RELEASE:
				{
					data.callback(MouseButtonReleasedEvent(button));
					break;
				}
			}
		});
		
		glfwSetScrollCallback(window, [](GLFWwindow* win, double xOffset, double yOffset) {
			WindowData& data = GET_DATA(win);

			data.callback(MouseScrolledEvent(xOffset, yOffset));
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* win, double xPos, double yPos) {
			WindowData& data = GET_DATA(win);

			data.callback(MouseMovedEvent(xPos, yPos));
		});
	}
}