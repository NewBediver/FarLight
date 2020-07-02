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

#include <glad/glad.h>

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
		glfwSwapBuffers(_window);
	}

	inline uint WindowsWindow::GetWidth() const { return _data._width; }
	inline uint WindowsWindow::GetHeight() const { return _data._height; }
	inline void WindowsWindow::SetEventCallback(const EventCallbackFunction& callback) { _data._callback = callback; }

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) glfwSwapInterval(1);
		else glfwSwapInterval(0);
		_data._isVSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return _data._isVSync;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		_data._title = props._title;
		_data._height = props._height;
		_data._width = props._width;

		// Disable before testing (Arise problems)
		//FL_CORE_INFO("Creating window {0} ({1}, {2})", props._title, props._width, props._height);

		if (!isGLFWInitialized)
		{
			int success = glfwInit();
			FL_CORE_ASSERT(success, "Could not initialize GLFW!");
			isGLFWInitialized = true;
		}

		_window = glfwCreateWindow(static_cast<int>(props._width), static_cast<int>(props._height), _data._title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		FL_CORE_ASSERT(status, "Failed to initialize Glad!");

		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);

		SetGLFWCallbacks();
	}

	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(_window);
	}

	void WindowsWindow::SetGLFWCallbacks()
	{
		#define GET_DATA(x) *static_cast<WindowData*>(glfwGetWindowUserPointer(x));

		glfwSetWindowSizeCallback(_window, [](GLFWwindow* win, int width, int height) {
			WindowData& data = GET_DATA(win);
			data._width = width;
			data._height = height;
			
			data._callback(WindowResizedEvent(width, height));
		});

		glfwSetWindowCloseCallback(_window, [](GLFWwindow* win) {
			WindowData& data = GET_DATA(win);

			data._callback(WindowClosedEvent());
		});

		glfwSetKeyCallback(_window, [](GLFWwindow* win, int key, int scan, int action, int mods) {
			WindowData& data = GET_DATA(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					data._callback(KeyboardKeyPressedEvent(key, 0));
					break;
				}
				case GLFW_RELEASE:
				{
					data._callback(KeyboardKeyReleasedEvent(key));
					break;
				}
				case GLFW_REPEAT:
				{
					data._callback(KeyboardKeyPressedEvent(key, 1));
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(_window, [](GLFWwindow* win, int button, int action, int mods) {
			WindowData& data = GET_DATA(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					data._callback(MouseButtonPressedEvent(button));
					break;
				}
				case GLFW_RELEASE:
				{
					data._callback(MouseButtonReleasedEvent(button));
					break;
				}
			}
		});
		
		glfwSetScrollCallback(_window, [](GLFWwindow* win, double xOffset, double yOffset) {
			WindowData& data = GET_DATA(win);

			data._callback(MouseScrolledEvent(xOffset, yOffset));
		});

		glfwSetCursorPosCallback(_window, [](GLFWwindow* win, double xPos, double yPos) {
			WindowData& data = GET_DATA(win);

			data._callback(MouseMovedEvent(xPos, yPos));
		});
	}
}