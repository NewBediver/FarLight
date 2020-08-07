#pragma once

#include <memory>

#include "KeyboardKeyCodes.h"
#include "MouseButtonCodes.h"

namespace FarLight
{
	class Input
	{
	public:
		static const Scope<Input>& GetInstance();

		static bool IsKeyPressed(KeyboardKeyCodes code) { return GetInstance()->IsKeyPressedImpl(code); }
		static bool IsMouseButtonPressed(MouseButtonCodes code) { return GetInstance()->IsMouseButtonPressedImpl(code); }
		static std::pair<double, double> GetMousePosition() { return GetInstance()->GetMousePositionImpl(); }
		static double GetMouseX() { return GetInstance()->GetMouseXImpl(); }
		static double GetMouseY() { return GetInstance()->GetMouseYImpl(); }

		static KeyboardKeyCodes GetFLKeyboardKeyCode(int code) { return GetInstance()->GetFLKeyboardKeyCodeImpl(code); }
		static MouseButtonCodes GetFLMouseButtonCode(int code) { return GetInstance()->GetFLMouseButtonCodeImpl(code); }

		Input(const Input&) = delete;
		Input(Input&&) = delete;
		Input& operator=(const Input&) = delete;
		Input& operator=(Input&&) = delete;

		virtual ~Input() = default;

	protected:
		explicit Input() = default;

		virtual bool IsKeyPressedImpl(KeyboardKeyCodes code) const = 0;
		virtual bool IsMouseButtonPressedImpl(MouseButtonCodes code) const = 0;
		virtual std::pair<double, double> GetMousePositionImpl() const = 0;
		virtual double GetMouseXImpl() const = 0;
		virtual double GetMouseYImpl() const = 0;

		virtual KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(int code) const = 0;
		virtual MouseButtonCodes GetFLMouseButtonCodeImpl(int code) const = 0;
	};
}