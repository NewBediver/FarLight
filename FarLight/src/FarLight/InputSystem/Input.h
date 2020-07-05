#pragma once

#include "flpch.h"

#include "FarLight/Core.h"

namespace FarLight
{
	class FARLIGHT_API Input
	{
	public:
		static bool IsKeyPressed(int keyCode) { return _instance->IsKeyPressedImpl(keyCode); }
		static bool IsMouseButtonPressed(int button) { return _instance->IsMouseButtonPressedImpl(button); }
		static std::pair<double, double> GetMousePosition() { return _instance->GetMousePositionImpl(); }
		static double GetMouseX() { return _instance->GetMouseXImpl(); }
		static double GetMouseY() { return _instance->GetMouseYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(int keyCode) const = 0;
		virtual bool IsMouseButtonPressedImpl(int button) const = 0;
		virtual std::pair<double, double> GetMousePositionImpl() const = 0;
		virtual double GetMouseXImpl() const = 0;
		virtual double GetMouseYImpl() const = 0;

	private:
		static Input* _instance;
	};
}