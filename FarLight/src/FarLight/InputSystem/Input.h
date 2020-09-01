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

        static bool IsKeyPressed(KeyboardKeyCode code) noexcept;
        static bool IsMouseButtonPressed(MouseButtonCode code) noexcept;
        static std::pair<double, double> GetMousePosition() noexcept;
        static double GetMouseX() noexcept;
        static double GetMouseY() noexcept;

    private:
        explicit Input() noexcept = default;

        #ifdef FL_PLATFORM_WINDOWS
            static int GetKeyboardKeyFromGLFW(KeyboardKeyCode code) noexcept;
            static int GetMouseButtonFromGLFW(MouseButtonCode code) noexcept;
        #endif
    };
}
