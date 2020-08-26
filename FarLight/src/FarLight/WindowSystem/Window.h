#pragma once

#include <functional>

#include "WindowProps.h"
#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class Window
	{
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window() noexcept = default;

		static Ref<Window> Create(const WindowProps& props = WindowProps()) noexcept;

		virtual void OnUpdate() noexcept = 0;

		virtual unsigned GetWidth() const noexcept = 0;
		virtual unsigned GetHeight() const noexcept = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) noexcept = 0;
		virtual void SetVSync(bool enabled) noexcept = 0;
		virtual bool IsVSync() const noexcept = 0;

		virtual Ref<void> GetNativeWindow() const noexcept = 0;
	};
}