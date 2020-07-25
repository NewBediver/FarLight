#pragma once

#include <memory>

#include "FarLight/Core/Core.h"
#include "KeyboardKeyCodes.h"
#include "MouseButtonCodes.h"

namespace FarLight
{
	class FARLIGHT_API Input
	{
	public:
		static const bool IsKeyPressed(const KeyboardKeyCodes code) { return _instance->IsKeyPressedImpl(code); }
		static const bool IsMouseButtonPressed(const MouseButtonCodes code) { return _instance->IsMouseButtonPressedImpl(code); }
		static const std::pair<double, double> GetMousePosition() { return _instance->GetMousePositionImpl(); }
		static const double GetMouseX() { return _instance->GetMouseXImpl(); }
		static const double GetMouseY() { return _instance->GetMouseYImpl(); }

		static const KeyboardKeyCodes GetFLKeyboardKeyCode(const int code) { return _instance->GetFLKeyboardKeyCodeImpl(code); }
		static const MouseButtonCodes GetFLMouseButtonCode(const int code) { return _instance->GetFLMouseButtonCodeImpl(code); }

		virtual ~Input() = default;

	protected:
		Input() = default;
		Input(const Input&) = delete;
		Input(Input&&) = delete;
		Input& operator=(const Input&) = delete;
		Input& operator=(Input&&) = delete;

		virtual const bool IsKeyPressedImpl(const KeyboardKeyCodes code) const = 0;
		virtual const bool IsMouseButtonPressedImpl(const MouseButtonCodes code) const = 0;
		virtual const std::pair<double, double> GetMousePositionImpl() const = 0;
		virtual const double GetMouseXImpl() const = 0;
		virtual const double GetMouseYImpl() const = 0;

		virtual const KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(const int code) const = 0;
		virtual const MouseButtonCodes GetFLMouseButtonCodeImpl(const int code) const = 0;

	private:
		static Scope<Input> _instance;
	};
}