#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyPressedEvent
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyPressedEvent(const int keyCode, const bool isRepeated)
			: KeyboardKeyEvent(keyCode, "KeyboardKeyPressed", EventType::KeyboardKeyPressedEventType)
			, _isRepeated(isRepeated) { }

		const bool IsRepeated() const { return _isRepeated; }

		virtual const std::string ToString() const override;

	private:
		bool _isRepeated;
	};
}