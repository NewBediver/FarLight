#pragma once

#include "KeyboardKeyEvent.h"

namespace FarLight
{
	class FARLIGHT_API KeyboardKeyPressedEvent
		: public KeyboardKeyEvent
	{
	public:
		explicit KeyboardKeyPressedEvent(int keyCode, bool isRepeated);

		static EventType GetStaticType();

		bool IsRepeated() const;

		virtual std::string ToString() const override;
		virtual EventType GetType() const override;
		virtual std::string GetName() const override;

	private:
		bool _isRepeated;
	};
}