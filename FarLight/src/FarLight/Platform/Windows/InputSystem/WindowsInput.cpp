#include "flpch.h"
#include "WindowsInput.h"

#include "FarLight/Application.h"

namespace FarLight
{
    Input* Input::_instance = new WindowsInput();

    bool WindowsInput::IsKeyPressedImpl(int keyCode) const
    {
        auto window = GetGLFWwindow();
        int status = glfwGetKey(window, keyCode);
        return status == GLFW_PRESS || status == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(int button) const
    {
        auto window = GetGLFWwindow();
        int status = glfwGetMouseButton(window, button);
        return status == GLFW_PRESS;
    }

    std::pair<double, double> WindowsInput::GetMousePositionImpl() const
    {
        auto window = GetGLFWwindow();
        double x, y;
        glfwGetCursorPos(window, &x, &y);
        return { x, y };
    }

    double WindowsInput::GetMouseXImpl() const
    {
        return GetMousePositionImpl().first;
    }

    double WindowsInput::GetMouseYImpl() const
    {
        return GetMousePositionImpl().second;
    }

    inline GLFWwindow* WindowsInput::GetGLFWwindow() const { return static_cast<GLFWwindow*>(Application::GetInstance()->GetWindow()->GetNativeWindow()); }
}