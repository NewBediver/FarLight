#pragma once

#include "FarLight/InputSystem/KeyboardKeyCodes.h"
#include "FarLight/InputSystem/MouseButtonCodes.h"

namespace FarLight
{
    class Input final
    {
    public:
        Input(const Input&) = delete;
        Input(Input&&) = delete;
        Input& operator=(const Input&) = delete;
        Input& operator=(Input&&) = delete;

        static Input& GetInstance() noexcept
        {
            static Input s_Instance;
            return s_Instance;
        }

        static bool IsKeyPressed(KeyboardKeyCodes code) noexcept;
        static bool IsMouseButtonPressed(MouseButtonCodes code) noexcept;
        static std::pair<double, double> GetMousePosition() noexcept;
        static double GetMouseX() noexcept;
        static double GetMouseY() noexcept;

    private:
        explicit Input() noexcept = default;

        static KeyboardKeyCodes GetFLKeyboardKeyCode(int code) noexcept;
        static MouseButtonCodes GetFLMouseButtonCode(int code) noexcept;

        static int GetKeyboardKeyFromGLFW(KeyboardKeyCodes code) noexcept;
        static int GetMouseButtonFromGLFW(MouseButtonCodes code) noexcept;
    };
}
