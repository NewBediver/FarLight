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

		virtual const unsigned int GetWidth() const override { return _data._width; }
		virtual const unsigned int GetHeight() const override { return _data._height; }

		virtual void SetEventCallback(const EventCallbackFunction& callback) override { _data._callback = callback; }

		virtual void SetVSync(bool enabled) override;
		virtual const bool IsVSync() const override { return _data._isVSync; }

		virtual Ref<void> GetNativeWindow() const override { return _window; }

	private:
		void Init(const WindowProps& props);

		void SetGLFWCallbacks();

		Ref<GLFWwindow> _window;
		Scope<OpenGLContext> _context;

		struct WindowData
		{
			std::string _title;
			unsigned int _width = 800, _height = 600;
			bool _isVSync = false;
			EventCallbackFunction _callback;
		} _data;
	};
}