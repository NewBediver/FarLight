#pragma once

#include <memory>

#include "KeyboardKeyCodes.h"
#include "MouseButtonCodes.h"

namespace FarLight
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyboardKeyCodes code) { return s_Instance->IsKeyPressedImpl(code); }
		static bool IsMouseButtonPressed(MouseButtonCodes code) { return s_Instance->IsMouseButtonPressedImpl(code); }
		static std::pair<double, double> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		static double GetMouseX() { return s_Instance->GetMouseXImpl(); }
		static double GetMouseY() { return s_Instance->GetMouseYImpl(); }

		static KeyboardKeyCodes GetFLKeyboardKeyCode(int code) { return s_Instance->GetFLKeyboardKeyCodeImpl(code); }
		static MouseButtonCodes GetFLMouseButtonCode(int code) { return s_Instance->GetFLMouseButtonCodeImpl(code); }

		virtual ~Input() = default;

	protected:
		Input() = default;
		Input(const Input&) = delete;
		Input(Input&&) = delete;
		Input& operator=(const Input&) = delete;
		Input& operator=(Input&&) = delete;

		virtual bool IsKeyPressedImpl(KeyboardKeyCodes code) const = 0;
		virtual bool IsMouseButtonPressedImpl(MouseButtonCodes code) const = 0;
		virtual std::pair<double, double> GetMousePositionImpl() const = 0;
		virtual double GetMouseXImpl() const = 0;
		virtual double GetMouseYImpl() const = 0;

		virtual KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(int code) const = 0;
		virtual MouseButtonCodes GetFLMouseButtonCodeImpl(int code) const = 0;

	private:
		static Scope<Input> s_Instance;
	};
}