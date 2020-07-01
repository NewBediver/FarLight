#pragma once

#include "FarLight/WindowSystem/Window.h"
#include "FarLight/WindowSystem/WindowProps.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	class FARLIGHT_API WindowsWindow
		: public Window
	{
	public:
		WindowsWindow() = delete;
		explicit WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		uint GetWidth() const override;
		uint GetHeight() const override;

		void SetEventCallback(const EventCallbackFunction& callback) override;
		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override;

	private:
		virtual void Init(const WindowProps& props);
		virtual void ShutDown();

		void SetGLFWCallbacks();

		GLFWwindow* _window;

		struct WindowData
		{
			std::string _title;
			uint _width, _height;
			bool _isVSync;
			EventCallbackFunction _callback;
		} _data;
	};
}

