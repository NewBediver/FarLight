#pragma once

#include <memory>

#include "KeyboardKeyCodes.h"
#include "MouseButtonCodes.h"

namespace FarLight
{
	class Input
	{
	public:
		Input(const Input&) = delete;
		Input(Input&&) = delete;
		Input& operator=(const Input&) = delete;
		Input& operator=(Input&&) = delete;

		virtual ~Input() noexcept = default;

		static const Scope<Input>& GetInstance() noexcept;

		static bool IsKeyPressed(KeyboardKeyCodes code) noexcept { return GetInstance()->IsKeyPressedImpl(code); }
		static bool IsMouseButtonPressed(MouseButtonCodes code) noexcept { return GetInstance()->IsMouseButtonPressedImpl(code); }
		static std::pair<double, double> GetMousePosition() noexcept { return GetInstance()->GetMousePositionImpl(); }
		static double GetMouseX() noexcept { return GetInstance()->GetMouseXImpl(); }
		static double GetMouseY() noexcept { return GetInstance()->GetMouseYImpl(); }

		static KeyboardKeyCodes GetFLKeyboardKeyCode(int code) noexcept { return GetInstance()->GetFLKeyboardKeyCodeImpl(code); }
		static MouseButtonCodes GetFLMouseButtonCode(int code) noexcept { return GetInstance()->GetFLMouseButtonCodeImpl(code); }

	protected:
		explicit Input() noexcept = default;

		virtual bool IsKeyPressedImpl(KeyboardKeyCodes code) const noexcept = 0;
		virtual bool IsMouseButtonPressedImpl(MouseButtonCodes code) const noexcept = 0;
		virtual std::pair<double, double> GetMousePositionImpl() const noexcept = 0;
		virtual double GetMouseXImpl() const noexcept = 0;
		virtual double GetMouseYImpl() const noexcept = 0;

		virtual KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(int code) const noexcept = 0;
		virtual MouseButtonCodes GetFLMouseButtonCodeImpl(int code) const noexcept = 0;
	};
}