#pragma once

#include "FarLight/InputSystem/Input.h"
#include "FarLight/Core/Application.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	class WindowsInput final
		: public Input
	{
	public:
		virtual bool IsKeyPressedImpl(KeyboardKeyCodes code) const override;
		virtual bool IsMouseButtonPressedImpl(MouseButtonCodes code) const override;
		virtual std::pair<double, double> GetMousePositionImpl() const override;
		virtual double GetMouseXImpl() const override;
		virtual double GetMouseYImpl() const override;

		virtual KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(int code) const override;
		virtual MouseButtonCodes GetFLMouseButtonCodeImpl(int code) const override;

	private:
		int GetKeyboardKeyFromGLFW(KeyboardKeyCodes code) const;
		int GetMouseButtonFromGLFW(MouseButtonCodes code) const;

		GLFWwindow* GetGLFWwindow() const { return static_cast<GLFWwindow*>(Application::GetInstance().GetWindow()->GetNativeWindow().get()); }
	};
}