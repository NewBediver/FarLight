#pragma once

#include "FarLight/InputSystem/Input.h"

#include <GLFW/glfw3.h>

namespace FarLight
{
	class FARLIGHT_API WindowsInput
		: public Input
	{
	public:
		virtual bool IsKeyPressedImpl(int keyCode) const override;
		virtual bool IsMouseButtonPressedImpl(int button) const override;
		virtual std::pair<double, double> GetMousePositionImpl() const override;
		virtual double GetMouseXImpl() const override;
		virtual double GetMouseYImpl() const override;

	private:
		GLFWwindow* GetGLFWwindow() const;
	};
}