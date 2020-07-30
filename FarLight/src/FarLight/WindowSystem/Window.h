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

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual Ref<void> GetNativeWindow() const = 0;

		virtual ~Window() = default;

		static Ref<Window> Create(const WindowProps& props = WindowProps());
	};
}