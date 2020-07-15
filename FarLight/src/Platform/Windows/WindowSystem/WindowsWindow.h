#pragma once

#include "FarLight/WindowSystem/Window.h"
#include "FarLight/WindowSystem/WindowProps.h"
#include "Platform/Renderer/OpenGL/Context/OpenGLContext.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	class FARLIGHT_API WindowsWindow
		: public Window
	{
	public:
		explicit WindowsWindow(const WindowProps& props);

		virtual void OnUpdate() override;

		virtual unsigned int GetWidth() const override { return _data._width; }
		virtual unsigned int GetHeight() const override { return _data._height; }

		virtual void SetEventCallback(const EventCallbackFunction& callback) override { _data._callback = callback; }

		virtual void SetVSync(bool enabled) override;
		virtual bool IsVSync() const override { return _data._isVSync; }

		virtual std::shared_ptr<void> GetNativeWindow() override { return _window; }

	private:
		void Init(const WindowProps& props);

		void SetGLFWCallbacks();

		std::shared_ptr<GLFWwindow> _window;
		std::shared_ptr<OpenGLContext> _context;

		struct WindowData
		{
			std::string _title;
			unsigned int _width, _height;
			bool _isVSync;
			EventCallbackFunction _callback;
		} _data;
	};
}