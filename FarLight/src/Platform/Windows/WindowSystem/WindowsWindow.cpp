// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

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
		FL_PROFILE_FUNCTION();

		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		FL_PROFILE_FUNCTION();

		if (enabled) glfwSwapInterval(1);
		else glfwSwapInterval(0);
		m_Data.IsVSync = enabled;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		FL_PROFILE_FUNCTION();

		m_Data.Title = props.Title;
		m_Data.Height = props.Height;
		m_Data.Width = props.Width;

		FL_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Height, m_Data.Width);

		if (!isGLFWInitialized)
		{
			{
				FL_PROFILE_SCOPE("glfwInit");

				int success = glfwInit();
				FL_CORE_ASSERT(success, "Could not initialize GLFW!");
			}
			
			glfwSetErrorCallback(GLFWErrorCallback);
			isGLFWInitialized = true;
		}

		{
			FL_PROFILE_SCOPE("glfwCreateWindow");

			m_Window = Ref<GLFWwindow>(glfwCreateWindow(static_cast<int>(m_Data.Width), static_cast<int>(m_Data.Height), m_Data.Title.c_str(), nullptr, nullptr), glfwDestroyWindow);
		}
		
		m_Context = CreateScope<OpenGLContext>(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window.get(), &m_Data);
		SetVSync(true);

		SetGLFWCallbacks();
	}

	void WindowsWindow::SetGLFWCallbacks()
	{
		FL_PROFILE_FUNCTION();

		#define GET_DATA(x) *static_cast<WindowData*>(glfwGetWindowUserPointer(x));

		glfwSetWindowSizeCallback(m_Window.get(), [](GLFWwindow* win, int width, int height) {
			FL_PROFILE_FUNCTION();

			WindowData& data = GET_DATA(win);
			data.Width = width;
			data.Height = height;
			
			data.Callback(WindowResizedEvent(width, height));
		});

		glfwSetWindowCloseCallback(m_Window.get(), [](GLFWwindow* win) {
			FL_PROFILE_FUNCTION();

			WindowData& data = GET_DATA(win);

			data.Callback(WindowClosedEvent());
		});

		glfwSetKeyCallback(m_Window.get(), [](GLFWwindow* win, int key, int scan, int action, int mods) {
			FL_PROFILE_FUNCTION();

			WindowData& data = GET_DATA(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					data.Callback(KeyboardKeyPressedEvent(key, 0));
					break;
				}
				case GLFW_RELEASE:
				{
					data.Callback(KeyboardKeyReleasedEvent(key));
					break;
				}
				case GLFW_REPEAT:
				{
					data.Callback(KeyboardKeyPressedEvent(key, 1));
					break;
				}
			}
		});

		glfwSetCharCallback(m_Window.get(), [](GLFWwindow* win, unsigned code) {
			FL_PROFILE_FUNCTION();

			WindowData& data = GET_DATA(win);

			data.Callback(KeyboardKeyTypedEvent(code));
		});

		glfwSetMouseButtonCallback(m_Window.get(), [](GLFWwindow* win, int button, int action, int mods) {
			FL_PROFILE_FUNCTION();

			WindowData& data = GET_DATA(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					data.Callback(MouseButtonPressedEvent(button));
					break;
				}
				case GLFW_RELEASE:
				{
					data.Callback(MouseButtonReleasedEvent(button));
					break;
				}
			}
		});
		
		glfwSetScrollCallback(m_Window.get(), [](GLFWwindow* win, double xOffset, double yOffset) {
			FL_PROFILE_FUNCTION();

			WindowData& data = GET_DATA(win);

			data.Callback(MouseScrolledEvent(xOffset, yOffset));
		});

		glfwSetCursorPosCallback(m_Window.get(), [](GLFWwindow* win, double xPos, double yPos) {
			FL_PROFILE_FUNCTION();

			WindowData& data = GET_DATA(win);

			data.Callback(MouseMovedEvent(xPos, yPos));
		});
	}
}