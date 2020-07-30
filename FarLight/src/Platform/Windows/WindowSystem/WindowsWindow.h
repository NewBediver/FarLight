#pragma once

#include "FarLight/WindowSystem/Window.h"
#include "FarLight/WindowSystem/WindowProps.h"
#include "Platform/Renderer/OpenGL/Context/OpenGLContext.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	class WindowsWindow
		: public Window
	{
	public:
		explicit WindowsWindow(const WindowProps& props);

		virtual void OnUpdate() override;

		virtual unsigned int GetWidth() const override { return m_Data.m_Width; }
		virtual unsigned int GetHeight() const override { return m_Data.m_Height; }

		virtual void SetEventCallback(const EventCallbackFunction& callback) override { m_Data.m_Callback = callback; }

		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override { return m_Data.m_IsVSync; }

		virtual Ref<void> GetNativeWindow() const override { return m_Window; }

	private:
		void Init(const WindowProps& props);

		void SetGLFWCallbacks();

		Ref<GLFWwindow> m_Window;
		Scope<OpenGLContext> m_Context;

		struct WindowData
		{
			std::string m_Title;
			unsigned int m_Width = 800, m_Height = 600;
			bool m_IsVSync = false;
			EventCallbackFunction m_Callback;
		} m_Data;
	};
}