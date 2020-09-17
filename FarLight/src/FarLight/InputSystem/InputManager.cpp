// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/InputSystem/InputManager.h"

#include "FarLight/BasicFunctionality/Application.h"

#ifdef FL_PLATFORM_WINDOWS
    #include <GLFW/glfw3.h>
#endif

namespace FarLight
{
    bool InputManager::IsKeyPressed(KeyboardKeyCode code) noexcept
    {
        FL_PROFILE_FUNCTION();

        int status;
        #ifdef FL_PLATFORM_WINDOWS
            status = glfwGetKey(static_cast<GLFWwindow*>(Application::GetInstance().GetWindow()->GetNativeWindow().get()), GetKeyboardKeyFromGLFW(code));
        #endif
        return status == GLFW_PRESS || status == GLFW_REPEAT;
    }

    bool InputManager::IsMouseButtonPressed(MouseButtonCode code) noexcept
    {
        FL_PROFILE_FUNCTION();

        int status;
        #ifdef FL_PLATFORM_WINDOWS
            status = glfwGetMouseButton(static_cast<GLFWwindow*>(Application::GetInstance().GetWindow()->GetNativeWindow().get()), GetMouseButtonFromGLFW(code));
        #endif
        return status == GLFW_PRESS;
    }

    std::pair<double, double> InputManager::GetMousePosition() noexcept
    {
        FL_PROFILE_FUNCTION();

        double x, y;
        #ifdef FL_PLATFORM_WINDOWS
            glfwGetCursorPos(static_cast<GLFWwindow*>(Application::GetInstance().GetWindow()->GetNativeWindow().get()), &x, &y);
        #endif
        return { x, y };
    }

    double InputManager::GetMouseX() noexcept
    {
        return GetMousePosition().first;
    }

    double InputManager::GetMouseY() noexcept
    {
        return GetMousePosition().second;
    }

    #ifdef FL_PLATFORM_WINDOWS
        int InputManager::GetKeyboardKeyFromGLFW(KeyboardKeyCode code) noexcept
        {
            switch (code)
            {
                case KeyboardKeyCode::FL_KEY_SPACE: return          GLFW_KEY_SPACE;
                case KeyboardKeyCode::FL_KEY_APOSTROPHE: return     GLFW_KEY_APOSTROPHE;
                case KeyboardKeyCode::FL_KEY_COMMA: return          GLFW_KEY_COMMA;
                case KeyboardKeyCode::FL_KEY_MINUS: return          GLFW_KEY_MINUS;
                case KeyboardKeyCode::FL_KEY_PERIOD: return         GLFW_KEY_PERIOD;
                case KeyboardKeyCode::FL_KEY_SLASH: return          GLFW_KEY_SLASH;
                case KeyboardKeyCode::FL_KEY_0: return              GLFW_KEY_0;
                case KeyboardKeyCode::FL_KEY_1: return              GLFW_KEY_1;
                case KeyboardKeyCode::FL_KEY_2: return              GLFW_KEY_2;
                case KeyboardKeyCode::FL_KEY_3: return              GLFW_KEY_3;
                case KeyboardKeyCode::FL_KEY_4: return              GLFW_KEY_4;
                case KeyboardKeyCode::FL_KEY_5: return              GLFW_KEY_5;
                case KeyboardKeyCode::FL_KEY_6: return              GLFW_KEY_6;
                case KeyboardKeyCode::FL_KEY_7: return              GLFW_KEY_7;
                case KeyboardKeyCode::FL_KEY_8: return              GLFW_KEY_8;
                case KeyboardKeyCode::FL_KEY_9: return              GLFW_KEY_9;
                case KeyboardKeyCode::FL_KEY_SEMICOLON: return      GLFW_KEY_SEMICOLON;
                case KeyboardKeyCode::FL_KEY_EQUAL: return          GLFW_KEY_EQUAL;
                case KeyboardKeyCode::FL_KEY_A: return              GLFW_KEY_A;
                case KeyboardKeyCode::FL_KEY_B: return              GLFW_KEY_B;
                case KeyboardKeyCode::FL_KEY_C: return              GLFW_KEY_C;
                case KeyboardKeyCode::FL_KEY_D: return              GLFW_KEY_D;
                case KeyboardKeyCode::FL_KEY_E: return              GLFW_KEY_E;
                case KeyboardKeyCode::FL_KEY_F: return              GLFW_KEY_F;
                case KeyboardKeyCode::FL_KEY_G: return              GLFW_KEY_G;
                case KeyboardKeyCode::FL_KEY_H: return              GLFW_KEY_H;
                case KeyboardKeyCode::FL_KEY_I: return              GLFW_KEY_I;
                case KeyboardKeyCode::FL_KEY_J: return              GLFW_KEY_J;
                case KeyboardKeyCode::FL_KEY_K: return              GLFW_KEY_K;
                case KeyboardKeyCode::FL_KEY_L: return              GLFW_KEY_L;
                case KeyboardKeyCode::FL_KEY_M: return              GLFW_KEY_M;
                case KeyboardKeyCode::FL_KEY_N: return              GLFW_KEY_N;
                case KeyboardKeyCode::FL_KEY_O: return              GLFW_KEY_O;
                case KeyboardKeyCode::FL_KEY_P: return              GLFW_KEY_P;
                case KeyboardKeyCode::FL_KEY_Q: return              GLFW_KEY_Q;
                case KeyboardKeyCode::FL_KEY_R: return              GLFW_KEY_R;
                case KeyboardKeyCode::FL_KEY_S: return              GLFW_KEY_S;
                case KeyboardKeyCode::FL_KEY_T: return              GLFW_KEY_T;
                case KeyboardKeyCode::FL_KEY_U: return              GLFW_KEY_U;
                case KeyboardKeyCode::FL_KEY_V: return              GLFW_KEY_V;
                case KeyboardKeyCode::FL_KEY_W: return              GLFW_KEY_W;
                case KeyboardKeyCode::FL_KEY_X: return              GLFW_KEY_X;
                case KeyboardKeyCode::FL_KEY_Y: return              GLFW_KEY_Y;
                case KeyboardKeyCode::FL_KEY_Z: return              GLFW_KEY_Z;
                case KeyboardKeyCode::FL_KEY_LEFT_BRACKET: return   GLFW_KEY_LEFT_BRACKET;
                case KeyboardKeyCode::FL_KEY_BACKSLASH: return      GLFW_KEY_BACKSLASH;
                case KeyboardKeyCode::FL_KEY_RIGHT_BRACKET: return  GLFW_KEY_RIGHT_BRACKET;
                case KeyboardKeyCode::FL_KEY_GRAVE_ACCENT: return   GLFW_KEY_GRAVE_ACCENT;
                case KeyboardKeyCode::FL_KEY_WORLD_1: return        GLFW_KEY_WORLD_1;
                case KeyboardKeyCode::FL_KEY_WORLD_2: return        GLFW_KEY_WORLD_2;
                case KeyboardKeyCode::FL_KEY_ESCAPE: return         GLFW_KEY_ESCAPE;
                case KeyboardKeyCode::FL_KEY_ENTER: return          GLFW_KEY_ENTER;
                case KeyboardKeyCode::FL_KEY_TAB: return            GLFW_KEY_TAB;
                case KeyboardKeyCode::FL_KEY_BACKSPACE: return      GLFW_KEY_BACKSPACE;
                case KeyboardKeyCode::FL_KEY_INSERT: return         GLFW_KEY_INSERT;
                case KeyboardKeyCode::FL_KEY_DELETE: return         GLFW_KEY_DELETE;
                case KeyboardKeyCode::FL_KEY_RIGHT: return          GLFW_KEY_RIGHT;
                case KeyboardKeyCode::FL_KEY_LEFT: return           GLFW_KEY_LEFT;
                case KeyboardKeyCode::FL_KEY_DOWN: return           GLFW_KEY_DOWN;
                case KeyboardKeyCode::FL_KEY_UP: return             GLFW_KEY_UP;
                case KeyboardKeyCode::FL_KEY_PAGE_UP: return        GLFW_KEY_PAGE_UP;
                case KeyboardKeyCode::FL_KEY_PAGE_DOWN: return      GLFW_KEY_PAGE_DOWN;
                case KeyboardKeyCode::FL_KEY_HOME: return           GLFW_KEY_HOME;
                case KeyboardKeyCode::FL_KEY_END: return            GLFW_KEY_END;
                case KeyboardKeyCode::FL_KEY_CAPS_LOCK: return      GLFW_KEY_CAPS_LOCK;
                case KeyboardKeyCode::FL_KEY_SCROLL_LOCK: return    GLFW_KEY_SCROLL_LOCK;
                case KeyboardKeyCode::FL_KEY_NUM_LOCK: return       GLFW_KEY_NUM_LOCK;
                case KeyboardKeyCode::FL_KEY_PRINT_SCREEN: return   GLFW_KEY_PRINT_SCREEN;
                case KeyboardKeyCode::FL_KEY_PAUSE: return          GLFW_KEY_PAUSE;
                case KeyboardKeyCode::FL_KEY_F1: return             GLFW_KEY_F1;
                case KeyboardKeyCode::FL_KEY_F2: return             GLFW_KEY_F2;
                case KeyboardKeyCode::FL_KEY_F3: return             GLFW_KEY_F3;
                case KeyboardKeyCode::FL_KEY_F4: return             GLFW_KEY_F4;
                case KeyboardKeyCode::FL_KEY_F5: return             GLFW_KEY_F5;
                case KeyboardKeyCode::FL_KEY_F6: return             GLFW_KEY_F6;
                case KeyboardKeyCode::FL_KEY_F7: return             GLFW_KEY_F7;
                case KeyboardKeyCode::FL_KEY_F8: return             GLFW_KEY_F8;
                case KeyboardKeyCode::FL_KEY_F9: return             GLFW_KEY_F9;
                case KeyboardKeyCode::FL_KEY_F10: return            GLFW_KEY_F10;
                case KeyboardKeyCode::FL_KEY_F11: return            GLFW_KEY_F11;
                case KeyboardKeyCode::FL_KEY_F12: return            GLFW_KEY_F12;
                case KeyboardKeyCode::FL_KEY_F13: return            GLFW_KEY_F13;
                case KeyboardKeyCode::FL_KEY_F14: return            GLFW_KEY_F14;
                case KeyboardKeyCode::FL_KEY_F15: return            GLFW_KEY_F15;
                case KeyboardKeyCode::FL_KEY_F16: return            GLFW_KEY_F16;
                case KeyboardKeyCode::FL_KEY_F17: return            GLFW_KEY_F17;
                case KeyboardKeyCode::FL_KEY_F18: return            GLFW_KEY_F18;
                case KeyboardKeyCode::FL_KEY_F19: return            GLFW_KEY_F19;
                case KeyboardKeyCode::FL_KEY_F20: return            GLFW_KEY_F20;
                case KeyboardKeyCode::FL_KEY_F21: return            GLFW_KEY_F21;
                case KeyboardKeyCode::FL_KEY_F22: return            GLFW_KEY_F22;
                case KeyboardKeyCode::FL_KEY_F23: return            GLFW_KEY_F23;
                case KeyboardKeyCode::FL_KEY_F24: return            GLFW_KEY_F24;
                case KeyboardKeyCode::FL_KEY_F25: return            GLFW_KEY_F25;
                case KeyboardKeyCode::FL_KEY_KP_0: return           GLFW_KEY_KP_0;
                case KeyboardKeyCode::FL_KEY_KP_1: return           GLFW_KEY_KP_1;
                case KeyboardKeyCode::FL_KEY_KP_2: return           GLFW_KEY_KP_2;
                case KeyboardKeyCode::FL_KEY_KP_3: return           GLFW_KEY_KP_3;
                case KeyboardKeyCode::FL_KEY_KP_4: return           GLFW_KEY_KP_4;
                case KeyboardKeyCode::FL_KEY_KP_5: return           GLFW_KEY_KP_5;
                case KeyboardKeyCode::FL_KEY_KP_6: return           GLFW_KEY_KP_6;
                case KeyboardKeyCode::FL_KEY_KP_7: return           GLFW_KEY_KP_7;
                case KeyboardKeyCode::FL_KEY_KP_8: return           GLFW_KEY_KP_8;
                case KeyboardKeyCode::FL_KEY_KP_9: return           GLFW_KEY_KP_9;
                case KeyboardKeyCode::FL_KEY_KP_DECIMAL: return     GLFW_KEY_KP_DECIMAL;
                case KeyboardKeyCode::FL_KEY_KP_DIVIDE: return      GLFW_KEY_KP_DIVIDE;
                case KeyboardKeyCode::FL_KEY_KP_MULTIPLY: return    GLFW_KEY_KP_MULTIPLY;
                case KeyboardKeyCode::FL_KEY_KP_SUBTRACT: return    GLFW_KEY_KP_SUBTRACT;
                case KeyboardKeyCode::FL_KEY_KP_ADD: return         GLFW_KEY_KP_ADD;
                case KeyboardKeyCode::FL_KEY_KP_ENTER: return       GLFW_KEY_KP_ENTER;
                case KeyboardKeyCode::FL_KEY_KP_EQUAL: return       GLFW_KEY_KP_EQUAL;
                case KeyboardKeyCode::FL_KEY_LEFT_SHIFT: return     GLFW_KEY_LEFT_SHIFT;
                case KeyboardKeyCode::FL_KEY_LEFT_CONTROL: return   GLFW_KEY_LEFT_CONTROL;
                case KeyboardKeyCode::FL_KEY_LEFT_ALT: return       GLFW_KEY_LEFT_ALT;
                case KeyboardKeyCode::FL_KEY_LEFT_SUPER: return     GLFW_KEY_LEFT_SUPER;
                case KeyboardKeyCode::FL_KEY_RIGHT_SHIFT: return    GLFW_KEY_RIGHT_SHIFT;
                case KeyboardKeyCode::FL_KEY_RIGHT_CONTROL: return  GLFW_KEY_RIGHT_CONTROL;
                case KeyboardKeyCode::FL_KEY_RIGHT_ALT: return      GLFW_KEY_RIGHT_ALT;
                case KeyboardKeyCode::FL_KEY_RIGHT_SUPER: return    GLFW_KEY_RIGHT_SUPER;
                case KeyboardKeyCode::FL_KEY_MENU: return           GLFW_KEY_MENU;
            }
            return GLFW_KEY_UNKNOWN;
        }
    
        int InputManager::GetMouseButtonFromGLFW(MouseButtonCode code) noexcept
        {
            switch (code)
            {
                case MouseButtonCode::FL_MOUSE_BUTTON_0: return          GLFW_MOUSE_BUTTON_1;
                case MouseButtonCode::FL_MOUSE_BUTTON_1: return          GLFW_MOUSE_BUTTON_2;
                case MouseButtonCode::FL_MOUSE_BUTTON_2: return          GLFW_MOUSE_BUTTON_3;
                case MouseButtonCode::FL_MOUSE_BUTTON_3: return          GLFW_MOUSE_BUTTON_4;
                case MouseButtonCode::FL_MOUSE_BUTTON_4: return          GLFW_MOUSE_BUTTON_5;
                case MouseButtonCode::FL_MOUSE_BUTTON_5: return          GLFW_MOUSE_BUTTON_6;
                case MouseButtonCode::FL_MOUSE_BUTTON_6: return          GLFW_MOUSE_BUTTON_7;
                case MouseButtonCode::FL_MOUSE_BUTTON_7: return          GLFW_MOUSE_BUTTON_8;
            }
            return GLFW_KEY_UNKNOWN;
        }
    #endif
}
