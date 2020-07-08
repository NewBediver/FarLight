#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyPressedEvent
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyPressedEvent(int keyCode, bool isRepeated)
			: KeyboardKeyEvent(keyCode), _isRepeated(isRepeated) { }

		static EventType GetStaticType() { return EventType::KeyboardKeyPressedEventType; }

		bool IsRepeated() const { return _isRepeated; }

		virtual std::string ToString() const override;
		virtual EventType GetType() const override { return GetStaticType(); }
		virtual std::string GetName() const override { return "KeyboardKeyPressed"; }

	private:
		bool _isRepeated;
	};
}