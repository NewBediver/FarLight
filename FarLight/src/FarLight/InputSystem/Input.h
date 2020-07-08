#pragma once

#include "flpch.h"

#include "FarLight/Core.h"

#include "KeyboardKeyCodes.h"
#include "MouseButtonCodes.h"

namespace FarLight
{
	class FARLIGHT_API Input
	{
	public:
		static bool IsKeyPressed(KeyboardKeyCodes code) { return _instance->IsKeyPressedImpl(code); }
		static bool IsMouseButtonPressed(MouseButtonCodes code) { return _instance->IsMouseButtonPressedImpl(code); }
		static std::pair<double, double> GetMousePosition() { return _instance->GetMousePositionImpl(); }
		static double GetMouseX() { return _instance->GetMouseXImpl(); }
		static double GetMouseY() { return _instance->GetMouseYImpl(); }

		static KeyboardKeyCodes GetFLKeyboardKeyCode(int code) { return _instance->GetFLKeyboardKeyCodeImpl(code); }
		static MouseButtonCodes GetFLMouseButtonCode(int code) { return _instance->GetFLMouseButtonCodeImpl(code); }

	protected:
		virtual bool IsKeyPressedImpl(KeyboardKeyCodes code) const = 0;
		virtual bool IsMouseButtonPressedImpl(MouseButtonCodes code) const = 0;
		virtual std::pair<double, double> GetMousePositionImpl() const = 0;
		virtual double GetMouseXImpl() const = 0;
		virtual double GetMouseYImpl() const = 0;

		virtual KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(int code) const = 0;
		virtual MouseButtonCodes GetFLMouseButtonCodeImpl(int code) const = 0;

	private:
		static std::shared_ptr<Input> _instance;
	};
}