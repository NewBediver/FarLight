#pragma once

#include "FarLight/WindowSystem/Window.h"
#include "FarLight/WindowSystem/WindowProps.h"
#include "Platform/Renderer/OpenGL/GraphicsContext/OpenGLContext.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	class WindowsWindow final
		: public Window
	{
	public:
		WindowsWindow(const WindowsWindow&) = delete;
		WindowsWindow(WindowsWindow&&) = delete;
		WindowsWindow& operator=(const WindowsWindow&) = delete;
		WindowsWindow& operator=(WindowsWindow&&) = delete;

		explicit WindowsWindow(const WindowProps& props) noexcept;

		virtual void OnUpdate() noexcept override;

		virtual unsigned GetWidth() const noexcept override { return m_Data.Width; }
		virtual unsigned GetHeight() const noexcept override { return m_Data.Height; }
		virtual void SetEventCallback(const EventCallbackFunction& callback) noexcept override { m_Data.Callback = callback; }

		virtual void SetVSync(bool enabled) noexcept override;
		virtual bool IsVSync() const noexcept override { return m_Data.IsVSync; }

		virtual Ref<void> GetNativeWindow() const noexcept override { return m_Window; }

	private:
		void Init(const WindowProps& props) noexcept;

		void SetGLFWCallbacks() noexcept;

		Ref<GLFWwindow> m_Window;
		Scope<OpenGLContext> m_Context;

		struct WindowData final
		{
			std::string Title;
			unsigned Width = 800, Height = 600;
			bool IsVSync = false;
			EventCallbackFunction Callback;
		} m_Data;
	};
}