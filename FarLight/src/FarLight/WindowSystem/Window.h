#pragma once

#include <memory>
#include <functional>

#include "WindowProps.h"
#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		static Ref<Window> Create(const WindowProps& props = WindowProps());

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned GetWidth() const = 0;
		virtual unsigned GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual Ref<void> GetNativeWindow() const = 0;
	};
}