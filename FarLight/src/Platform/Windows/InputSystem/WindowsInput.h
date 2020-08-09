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
		virtual bool IsKeyPressedImpl(KeyboardKeyCodes code) const noexcept override;
		virtual bool IsMouseButtonPressedImpl(MouseButtonCodes code) const noexcept override;
		virtual std::pair<double, double> GetMousePositionImpl() const noexcept override;
		virtual double GetMouseXImpl() const noexcept override;
		virtual double GetMouseYImpl() const noexcept override;

		virtual KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(int code) const noexcept override;
		virtual MouseButtonCodes GetFLMouseButtonCodeImpl(int code) const noexcept override;

	private:
		constexpr
		int GetKeyboardKeyFromGLFW(KeyboardKeyCodes code) const noexcept;
		constexpr
		int GetMouseButtonFromGLFW(MouseButtonCodes code) const noexcept;

		GLFWwindow* GetGLFWwindow() const noexcept { return static_cast<GLFWwindow*>(Application::GetInstance().GetWindow()->GetNativeWindow().get()); }
	};
}