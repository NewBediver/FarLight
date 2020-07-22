#pragma once

#include "FarLight/InputSystem/Input.h"
#include "FarLight/Application.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	class FARLIGHT_API WindowsInput
		: public Input
	{
	public:
		virtual const bool IsKeyPressedImpl(const KeyboardKeyCodes code) const override;
		virtual const bool IsMouseButtonPressedImpl(const MouseButtonCodes code) const override;
		virtual const std::pair<double, double> GetMousePositionImpl() const override;
		virtual const double GetMouseXImpl() const override;
		virtual const double GetMouseYImpl() const override;

		virtual const KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(const int code) const override;
		virtual const MouseButtonCodes GetFLMouseButtonCodeImpl(const int code) const override;

	private:
		const int GetKeyboardKeyFromGLFW(const KeyboardKeyCodes code) const;
		const int GetMouseButtonFromGLFW(const MouseButtonCodes code) const;

		GLFWwindow* GetGLFWwindow() const { return static_cast<GLFWwindow*>(Application::GetInstance()->GetWindow()->GetNativeWindow().get()); }
	};
}