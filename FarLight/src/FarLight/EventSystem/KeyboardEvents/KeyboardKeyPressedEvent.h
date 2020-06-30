#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyPressedEvent
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyPressedEvent(int keyCode, int repeatCount);

		static EventType GetStaticType();

		int GetRepeatCount() const;

		virtual std::string ToString() const override;
		virtual EventType GetType() const override;
		virtual std::string GetName() const override;

	private:
		int repeatCount;
	};
}