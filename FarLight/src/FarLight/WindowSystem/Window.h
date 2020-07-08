#pragma once

#include "WindowProps.h"

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual std::shared_ptr<void> GetNativeWindow() = 0;

		static std::shared_ptr<Window> Create(const WindowProps& props = WindowProps());
	};
}
