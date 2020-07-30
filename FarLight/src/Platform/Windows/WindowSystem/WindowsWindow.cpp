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
		glfwPollEvents();
		m_Context->SwapBuffers();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) glfwSwapInterval(1);
		else glfwSwapInterval(0);
		m_Data.m_IsVSync = enabled;
	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.m_Title = props.m_Title;
		m_Data.m_Height = props.m_Height;
		m_Data.m_Width = props.m_Width;

		FL_CORE_INFO("Creating window {0} ({1}, {2})", props.m_Title, props.m_Height, props.m_Width);

		if (!isGLFWInitialized)
		{
			int success = glfwInit();
			FL_CORE_ASSERT(success, "Could not initialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);
			isGLFWInitialized = true;
		}

		m_Window = Ref<GLFWwindow>(glfwCreateWindow(static_cast<int>(props.m_Width), static_cast<int>(props.m_Height), m_Data.m_Title.c_str(), nullptr, nullptr), glfwDestroyWindow);
		
		m_Context = CreateScope<OpenGLContext>(m_Window);
		m_Context->Init();

		glfwSetWindowUserPointer(m_Window.get(), &m_Data);
		SetVSync(true);

		SetGLFWCallbacks();
	}

	void WindowsWindow::SetGLFWCallbacks()
	{
		#define GET_DATA(x) *static_cast<WindowData*>(glfwGetWindowUserPointer(x));

		glfwSetWindowSizeCallback(m_Window.get(), [](GLFWwindow* win, int width, int height) {
			WindowData& data = GET_DATA(win);
			data.m_Width = width;
			data.m_Height = height;
			
			data.m_Callback(WindowResizedEvent(width, height));
		});

		glfwSetWindowCloseCallback(m_Window.get(), [](GLFWwindow* win) {
			WindowData& data = GET_DATA(win);

			data.m_Callback(WindowClosedEvent());
		});

		glfwSetKeyCallback(m_Window.get(), [](GLFWwindow* win, int key, int scan, int action, int mods) {
			WindowData& data = GET_DATA(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					data.m_Callback(KeyboardKeyPressedEvent(key, 0));
					break;
				}
				case GLFW_RELEASE:
				{
					data.m_Callback(KeyboardKeyReleasedEvent(key));
					break;
				}
				case GLFW_REPEAT:
				{
					data.m_Callback(KeyboardKeyPressedEvent(key, 1));
					break;
				}
			}
		});

		glfwSetCharCallback(m_Window.get(), [](GLFWwindow* win, unsigned int code) {
			WindowData& data = GET_DATA(win);

			data.m_Callback(KeyboardKeyTypedEvent(code));
		});

		glfwSetMouseButtonCallback(m_Window.get(), [](GLFWwindow* win, int button, int action, int mods) {
			WindowData& data = GET_DATA(win);

			switch (action)
			{
				case GLFW_PRESS:
				{
					data.m_Callback(MouseButtonPressedEvent(button));
					break;
				}
				case GLFW_RELEASE:
				{
					data.m_Callback(MouseButtonReleasedEvent(button));
					break;
				}
			}
		});
		
		glfwSetScrollCallback(m_Window.get(), [](GLFWwindow* win, double xOffset, double yOffset) {
			WindowData& data = GET_DATA(win);

			data.m_Callback(MouseScrolledEvent(xOffset, yOffset));
		});

		glfwSetCursorPosCallback(m_Window.get(), [](GLFWwindow* win, double xPos, double yPos) {
			WindowData& data = GET_DATA(win);

			data.m_Callback(MouseMovedEvent(xPos, yPos));
		});
	}
}