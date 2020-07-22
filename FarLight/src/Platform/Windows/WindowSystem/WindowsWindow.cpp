#include "flpch.h"

#include "WindowsWindow.h"

#include "FarLight/EventSystem/WindowEvents/WindowResizedEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowClosedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyPressedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyReleasedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyTypedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseButtonPressedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseButtonReleasedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseMovedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseScrolledEvent.h"

#include <glad/glad.h>

namespace FarLight
{
	static bool isGLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		FL_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		_context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) glfwSwapInterval(1);
		else glfwSwapInterval(0);
		_data._isVSync = enabled;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		_data._title = props._title;
		_data._height = props._height;
		_data._width = props._width;

		// Disable before testing (Arise problems)
		FL_CORE_INFO("Creating window {0} ({1}, {2})", props._title, props._width, props._height);

		if (!isGLFWInitialized)
		{
			int success = glfwInit();
			FL_CORE_ASSERT(success, "Could not initialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);
			isGLFWInitialized = true;
		}

		_window = Ref<GLFWwindow>(glfwCreateWindow(static_cast<int>(props._width), static_cast<int>(props._height), _data._title.c_str(), nullptr, nullptr), glfwDestroyWindow);
		
		_context = Scope<OpenGLContext>(new OpenGLContext(_window));
		_context->Init();

		glfwSetWindowUserPointer(_window.get(), &_data);
		SetVSync(true);

		SetGLFWCallbacks();
	}

	void WindowsWindow::SetGLFWCallbacks()
	{
		#define GET_DATA(x) *static_cast<WindowData*>(glfwGetWindowUserPointer(x));

		glfwSetWindowSizeCallback(_window.get(), [](GLFWwindow* win, int width, int height) {
			WindowData& data = GET_DATA(win);
			data._width = width;
			data._height = height;
			
			glViewport(0, 0, data._width, data._height);
			data._callback(WindowResizedEvent(width, height));
		});

		glfwSetWindowCloseCallback(_window.get(), [](GLFWwindow* win) {
			WindowData& data = GET_DATA(win);

			data._callback(WindowClosedEvent());
		});

		glfwSetKeyCallback(_window.get(), [](GLFWwindow* win, int key, int scan, int action, int mods) {
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

		glfwSetCharCallback(_window.get(), [](GLFWwindow* win, unsigned int code) {
			WindowData& data = GET_DATA(win);

			data._callback(KeyboardKeyTypedEvent(code));
		});

		glfwSetMouseButtonCallback(_window.get(), [](GLFWwindow* win, int button, int action, int mods) {
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
		
		glfwSetScrollCallback(_window.get(), [](GLFWwindow* win, double xOffset, double yOffset) {
			WindowData& data = GET_DATA(win);

			data._callback(MouseScrolledEvent(xOffset, yOffset));
		});

		glfwSetCursorPosCallback(_window.get(), [](GLFWwindow* win, double xPos, double yPos) {
			WindowData& data = GET_DATA(win);

			data._callback(MouseMovedEvent(xPos, yPos));
		});
	}
}