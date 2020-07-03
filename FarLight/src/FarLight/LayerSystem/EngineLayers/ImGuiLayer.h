#pragma once

#include "FarLight/LayerSystem/Layer.h"
#include "FarLight/Application.h"

#include "FarLight/EventSystem/MouseEvents/MouseButtonPressedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseButtonReleasedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseMovedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseScrolledEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyPressedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyReleasedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyTypedEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowResizedEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowClosedEvent.h"

namespace FarLight
{
	class FARLIGHT_API ImGuiLayer
		: public Layer
	{
	public:
		ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& event) override;

	private:
		bool OnMouseButtonPressedEvent(const MouseButtonPressedEvent& e);
		bool OnMouseButtonReleasedEvent(const MouseButtonReleasedEvent& e);
		bool OnMouseMovedEvent(const MouseMovedEvent& e);
		bool OnMouseScrolledEvent(const MouseScrolledEvent& e);
		bool OnKeyboardKeyPressedEvent(const KeyboardKeyPressedEvent& e);
		bool OnKeyboardKeyReleasedEvent(const KeyboardKeyReleasedEvent& e);
		bool OnKeyboardKeyTypedEvent(const KeyboardKeyTypedEvent& e);
		bool OnWindowResizedEvent(const WindowResizedEvent& e);

		double _time;
	};
}