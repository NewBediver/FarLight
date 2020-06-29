#pragma once

#include "flpch.h"

#include "FarLight/EventSystem/Event.h"
#include "WindowProps.h"

namespace FarLight
{
	class FARLIGHT_API Window
	{
	public:
		using uint = unsigned int;
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window();

		virtual void OnUpdate() = 0;

		virtual uint GetWidth() const = 0;
		virtual uint GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}
