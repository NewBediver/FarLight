#pragma once

#include "FarLight/WindowSystem/Window.h"
#include "FarLight/WindowSystem/WindowProps.h"
#include "Platform/Renderer/OpenGL/Context/OpenGLContext.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	class WindowsWindow final
		: public Window
	{
	public:
		explicit WindowsWindow(const WindowProps& props);

		virtual void OnUpdate() override;

		virtual unsigned GetWidth() const override { return m_Data.Width; }
		virtual unsigned GetHeight() const override { return m_Data.Height; }

		virtual void SetEventCallback(const EventCallbackFunction& callback) override { m_Data.Callback = callback; }

		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override { return m_Data.IsVSync; }

		virtual Ref<void> GetNativeWindow() const override { return m_Window; }

	private:
		void Init(const WindowProps& props);

		void SetGLFWCallbacks();

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