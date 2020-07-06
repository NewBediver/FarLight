#include "InputLayer.h"

void InputLayer::OnAttach()
{
}

void InputLayer::OnDetach()
{
}

void InputLayer::OnUpdate()
{
}

void InputLayer::OnEvent(Event& event)
{
	if (event.GetType() == EventType::KeyboardKeyPressedEventType)
	{
		if (Input::IsKeyPressed(Input::GetFLKeyboardKeyCode(static_cast<KeyboardKeyTypedEvent&>(event).GetKeyCode())) && Input::GetFLKeyboardKeyCode(static_cast<KeyboardKeyTypedEvent&>(event).GetKeyCode()) == KeyboardKeyCodes::FL_KEY_TAB)
			FL_TRACE("Tab key is pressed!");
	}
}
