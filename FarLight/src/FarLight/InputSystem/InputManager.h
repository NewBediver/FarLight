#pragma once

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/InputSystem/KeyboardKeyCodes.h"
#include "FarLight/InputSystem/MouseButtonCodes.h"

namespace FarLight
{
    class InputManager
        : public Singleton<InputManager>
    {
    public:
        bool IsKeyPressed(KeyboardKeyCode code) noexcept;
        bool IsMouseButtonPressed(MouseButtonCode code) noexcept;
        std::pair<double, double> GetMousePosition() noexcept;
        double GetMouseX() noexcept;
        double GetMouseY() noexcept;

    private:
        #ifdef FL_PLATFORM_WINDOWS
            int GetKeyboardKeyFromGLFW(KeyboardKeyCode code) noexcept;
            int GetMouseButtonFromGLFW(MouseButtonCode code) noexcept;
        #endif
    };
}
