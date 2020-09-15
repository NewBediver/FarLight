#pragma once

#include "FarLight/Abstraction/Singleton/Singleton.h"

#include "FarLight/InputSystem/KeyboardKeyCodes.h"
#include "FarLight/InputSystem/MouseButtonCodes.h"

namespace FarLight
{
    class Input
        : public Singleton<Input>
    {
    public:
        Input() = default;
        ~Input() = default;

        static bool IsKeyPressed(KeyboardKeyCode code) noexcept;
        static bool IsMouseButtonPressed(MouseButtonCode code) noexcept;
        static std::pair<double, double> GetMousePosition() noexcept;
        static double GetMouseX() noexcept;
        static double GetMouseY() noexcept;

    private:
        #ifdef FL_PLATFORM_WINDOWS
            static int GetKeyboardKeyFromGLFW(KeyboardKeyCode code) noexcept;
            static int GetMouseButtonFromGLFW(MouseButtonCode code) noexcept;
        #endif
    };
}
