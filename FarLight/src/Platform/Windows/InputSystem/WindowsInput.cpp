#include "flpch.h"

#include "WindowsInput.h"

#include "FarLight/Application.h"

namespace FarLight
{
    bool WindowsInput::IsKeyPressedImpl(KeyboardKeyCodes code) const
    {
        int key = GetKeyboardKeyFromGLFW(code);
        auto window = GetGLFWwindow();
        int status = glfwGetKey(window, key);
        return status == GLFW_PRESS || status == GLFW_REPEAT;
    }

    bool WindowsInput::IsMouseButtonPressedImpl(MouseButtonCodes code) const
    {
        int key = GetMouseButtonFromGLFW(code);
        auto window = GetGLFWwindow();
        int status = glfwGetMouseButton(window, key);
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

    KeyboardKeyCodes WindowsInput::GetFLKeyboardKeyCodeImpl(int code) const
    {
        switch (code)
        {
            case GLFW_KEY_SPACE: return              KeyboardKeyCodes::FL_KEY_SPACE;
            case GLFW_KEY_APOSTROPHE: return         KeyboardKeyCodes::FL_KEY_APOSTROPHE;
            case GLFW_KEY_COMMA: return              KeyboardKeyCodes::FL_KEY_COMMA;
            case GLFW_KEY_MINUS: return              KeyboardKeyCodes::FL_KEY_MINUS;
            case GLFW_KEY_PERIOD: return             KeyboardKeyCodes::FL_KEY_PERIOD;
            case GLFW_KEY_SLASH: return              KeyboardKeyCodes::FL_KEY_SLASH;
            case GLFW_KEY_0: return                  KeyboardKeyCodes::FL_KEY_0;
            case GLFW_KEY_1: return                  KeyboardKeyCodes::FL_KEY_1;
            case GLFW_KEY_2: return                  KeyboardKeyCodes::FL_KEY_2;
            case GLFW_KEY_3: return                  KeyboardKeyCodes::FL_KEY_3;
            case GLFW_KEY_4: return                  KeyboardKeyCodes::FL_KEY_4;
            case GLFW_KEY_5: return                  KeyboardKeyCodes::FL_KEY_5;
            case GLFW_KEY_6: return                  KeyboardKeyCodes::FL_KEY_6;
            case GLFW_KEY_7: return                  KeyboardKeyCodes::FL_KEY_7;
            case GLFW_KEY_8: return                  KeyboardKeyCodes::FL_KEY_8;
            case GLFW_KEY_9: return                  KeyboardKeyCodes::FL_KEY_9;
            case GLFW_KEY_SEMICOLON: return          KeyboardKeyCodes::FL_KEY_SEMICOLON;
            case GLFW_KEY_EQUAL: return              KeyboardKeyCodes::FL_KEY_EQUAL;
            case GLFW_KEY_A: return                  KeyboardKeyCodes::FL_KEY_A;
            case GLFW_KEY_B: return                  KeyboardKeyCodes::FL_KEY_B;
            case GLFW_KEY_C: return                  KeyboardKeyCodes::FL_KEY_C;
            case GLFW_KEY_D: return                  KeyboardKeyCodes::FL_KEY_D;
            case GLFW_KEY_E: return                  KeyboardKeyCodes::FL_KEY_E;
            case GLFW_KEY_F: return                  KeyboardKeyCodes::FL_KEY_F;
            case GLFW_KEY_G: return                  KeyboardKeyCodes::FL_KEY_G;
            case GLFW_KEY_H: return                  KeyboardKeyCodes::FL_KEY_H;
            case GLFW_KEY_I: return                  KeyboardKeyCodes::FL_KEY_I;
            case GLFW_KEY_J: return                  KeyboardKeyCodes::FL_KEY_J;
            case GLFW_KEY_K: return                  KeyboardKeyCodes::FL_KEY_K;
            case GLFW_KEY_L: return                  KeyboardKeyCodes::FL_KEY_L;
            case GLFW_KEY_M: return                  KeyboardKeyCodes::FL_KEY_M;
            case GLFW_KEY_N: return                  KeyboardKeyCodes::FL_KEY_N;
            case GLFW_KEY_O: return                  KeyboardKeyCodes::FL_KEY_O;
            case GLFW_KEY_P: return                  KeyboardKeyCodes::FL_KEY_P;
            case GLFW_KEY_Q: return                  KeyboardKeyCodes::FL_KEY_Q;
            case GLFW_KEY_R: return                  KeyboardKeyCodes::FL_KEY_R;
            case GLFW_KEY_S: return                  KeyboardKeyCodes::FL_KEY_S;
            case GLFW_KEY_T: return                  KeyboardKeyCodes::FL_KEY_T;
            case GLFW_KEY_U: return                  KeyboardKeyCodes::FL_KEY_U;
            case GLFW_KEY_V: return                  KeyboardKeyCodes::FL_KEY_V;
            case GLFW_KEY_W: return                  KeyboardKeyCodes::FL_KEY_W;
            case GLFW_KEY_X: return                  KeyboardKeyCodes::FL_KEY_X;
            case GLFW_KEY_Y: return                  KeyboardKeyCodes::FL_KEY_Y;
            case GLFW_KEY_Z: return                  KeyboardKeyCodes::FL_KEY_Z;
            case GLFW_KEY_LEFT_BRACKET: return       KeyboardKeyCodes::FL_KEY_LEFT_BRACKET;
            case GLFW_KEY_BACKSLASH: return          KeyboardKeyCodes::FL_KEY_BACKSLASH;
            case GLFW_KEY_RIGHT_BRACKET: return      KeyboardKeyCodes::FL_KEY_RIGHT_BRACKET;
            case GLFW_KEY_GRAVE_ACCENT: return       KeyboardKeyCodes::FL_KEY_GRAVE_ACCENT;
            case GLFW_KEY_WORLD_1: return            KeyboardKeyCodes::FL_KEY_WORLD_1;
            case GLFW_KEY_WORLD_2: return            KeyboardKeyCodes::FL_KEY_WORLD_2;
            case GLFW_KEY_ESCAPE: return             KeyboardKeyCodes::FL_KEY_ESCAPE;
            case GLFW_KEY_ENTER: return              KeyboardKeyCodes::FL_KEY_ENTER;
            case GLFW_KEY_TAB: return                KeyboardKeyCodes::FL_KEY_TAB;
            case GLFW_KEY_BACKSPACE: return          KeyboardKeyCodes::FL_KEY_BACKSPACE;
            case GLFW_KEY_INSERT: return             KeyboardKeyCodes::FL_KEY_INSERT;
            case GLFW_KEY_DELETE: return             KeyboardKeyCodes::FL_KEY_DELETE;
            case GLFW_KEY_RIGHT: return              KeyboardKeyCodes::FL_KEY_RIGHT;
            case GLFW_KEY_LEFT: return               KeyboardKeyCodes::FL_KEY_LEFT;
            case GLFW_KEY_DOWN: return               KeyboardKeyCodes::FL_KEY_DOWN;
            case GLFW_KEY_UP: return                 KeyboardKeyCodes::FL_KEY_UP;
            case GLFW_KEY_PAGE_UP: return            KeyboardKeyCodes::FL_KEY_PAGE_UP;
            case GLFW_KEY_PAGE_DOWN: return          KeyboardKeyCodes::FL_KEY_PAGE_DOWN;
            case GLFW_KEY_HOME: return               KeyboardKeyCodes::FL_KEY_HOME;
            case GLFW_KEY_END: return                KeyboardKeyCodes::FL_KEY_END;
            case GLFW_KEY_CAPS_LOCK: return          KeyboardKeyCodes::FL_KEY_CAPS_LOCK;
            case GLFW_KEY_SCROLL_LOCK: return        KeyboardKeyCodes::FL_KEY_SCROLL_LOCK;
            case GLFW_KEY_NUM_LOCK: return           KeyboardKeyCodes::FL_KEY_NUM_LOCK;
            case GLFW_KEY_PRINT_SCREEN: return       KeyboardKeyCodes::FL_KEY_PRINT_SCREEN;
            case GLFW_KEY_PAUSE: return              KeyboardKeyCodes::FL_KEY_PAUSE;
            case GLFW_KEY_F1: return                 KeyboardKeyCodes::FL_KEY_F1;
            case GLFW_KEY_F2: return                 KeyboardKeyCodes::FL_KEY_F2;
            case GLFW_KEY_F3: return                 KeyboardKeyCodes::FL_KEY_F3;
            case GLFW_KEY_F4: return                 KeyboardKeyCodes::FL_KEY_F4;
            case GLFW_KEY_F5: return                 KeyboardKeyCodes::FL_KEY_F5;
            case GLFW_KEY_F6: return                 KeyboardKeyCodes::FL_KEY_F6;
            case GLFW_KEY_F7: return                 KeyboardKeyCodes::FL_KEY_F7;
            case GLFW_KEY_F8: return                 KeyboardKeyCodes::FL_KEY_F8;
            case GLFW_KEY_F9: return                 KeyboardKeyCodes::FL_KEY_F9;
            case GLFW_KEY_F10: return                KeyboardKeyCodes::FL_KEY_F10;
            case GLFW_KEY_F11: return                KeyboardKeyCodes::FL_KEY_F11;
            case GLFW_KEY_F12: return                KeyboardKeyCodes::FL_KEY_F12;
            case GLFW_KEY_F13: return                KeyboardKeyCodes::FL_KEY_F13;
            case GLFW_KEY_F14: return                KeyboardKeyCodes::FL_KEY_F14;
            case GLFW_KEY_F15: return                KeyboardKeyCodes::FL_KEY_F15;
            case GLFW_KEY_F16: return                KeyboardKeyCodes::FL_KEY_F16;
            case GLFW_KEY_F17: return                KeyboardKeyCodes::FL_KEY_F17;
            case GLFW_KEY_F18: return                KeyboardKeyCodes::FL_KEY_F18;
            case GLFW_KEY_F19: return                KeyboardKeyCodes::FL_KEY_F19;
            case GLFW_KEY_F20: return                KeyboardKeyCodes::FL_KEY_F20;
            case GLFW_KEY_F21: return                KeyboardKeyCodes::FL_KEY_F21;
            case GLFW_KEY_F22: return                KeyboardKeyCodes::FL_KEY_F22;
            case GLFW_KEY_F23: return                KeyboardKeyCodes::FL_KEY_F23;
            case GLFW_KEY_F24: return                KeyboardKeyCodes::FL_KEY_F24;
            case GLFW_KEY_F25: return                KeyboardKeyCodes::FL_KEY_F25;
            case GLFW_KEY_KP_0: return               KeyboardKeyCodes::FL_KEY_KP_0;
            case GLFW_KEY_KP_1: return               KeyboardKeyCodes::FL_KEY_KP_1;
            case GLFW_KEY_KP_2: return               KeyboardKeyCodes::FL_KEY_KP_2;
            case GLFW_KEY_KP_3: return               KeyboardKeyCodes::FL_KEY_KP_3;
            case GLFW_KEY_KP_4: return               KeyboardKeyCodes::FL_KEY_KP_4;
            case GLFW_KEY_KP_5: return               KeyboardKeyCodes::FL_KEY_KP_5;
            case GLFW_KEY_KP_6: return               KeyboardKeyCodes::FL_KEY_KP_6;
            case GLFW_KEY_KP_7: return               KeyboardKeyCodes::FL_KEY_KP_7;
            case GLFW_KEY_KP_8: return               KeyboardKeyCodes::FL_KEY_KP_8;
            case GLFW_KEY_KP_9: return               KeyboardKeyCodes::FL_KEY_KP_9;
            case GLFW_KEY_KP_DECIMAL: return         KeyboardKeyCodes::FL_KEY_KP_DECIMAL;
            case GLFW_KEY_KP_DIVIDE: return          KeyboardKeyCodes::FL_KEY_KP_DIVIDE;
            case GLFW_KEY_KP_MULTIPLY: return        KeyboardKeyCodes::FL_KEY_KP_MULTIPLY;
            case GLFW_KEY_KP_SUBTRACT: return        KeyboardKeyCodes::FL_KEY_KP_SUBTRACT;
            case GLFW_KEY_KP_ADD: return             KeyboardKeyCodes::FL_KEY_KP_ADD;
            case GLFW_KEY_KP_ENTER: return           KeyboardKeyCodes::FL_KEY_KP_ENTER;
            case GLFW_KEY_KP_EQUAL: return           KeyboardKeyCodes::FL_KEY_KP_EQUAL;
            case GLFW_KEY_LEFT_SHIFT: return         KeyboardKeyCodes::FL_KEY_LEFT_SHIFT;
            case GLFW_KEY_LEFT_CONTROL: return       KeyboardKeyCodes::FL_KEY_LEFT_CONTROL;
            case GLFW_KEY_LEFT_ALT: return           KeyboardKeyCodes::FL_KEY_LEFT_ALT;
            case GLFW_KEY_LEFT_SUPER: return         KeyboardKeyCodes::FL_KEY_LEFT_SUPER;
            case GLFW_KEY_RIGHT_SHIFT: return        KeyboardKeyCodes::FL_KEY_RIGHT_SHIFT;
            case GLFW_KEY_RIGHT_CONTROL: return      KeyboardKeyCodes::FL_KEY_RIGHT_CONTROL;
            case GLFW_KEY_RIGHT_ALT: return          KeyboardKeyCodes::FL_KEY_RIGHT_ALT;
            case GLFW_KEY_RIGHT_SUPER: return        KeyboardKeyCodes::FL_KEY_RIGHT_SUPER;
            case GLFW_KEY_MENU: return               KeyboardKeyCodes::FL_KEY_MENU;
        }
        return KeyboardKeyCodes::FL_KEY_UNKNOWN;
    }

    MouseButtonCodes WindowsInput::GetFLMouseButtonCodeImpl(int code) const
    {
        switch (code)
        {
            case GLFW_MOUSE_BUTTON_1: return MouseButtonCodes::FL_MOUSE_BUTTON_LEFT;
            case GLFW_MOUSE_BUTTON_2: return MouseButtonCodes::FL_MOUSE_BUTTON_RIGHT;
            case GLFW_MOUSE_BUTTON_3: return MouseButtonCodes::FL_MOUSE_BUTTON_MIDDLE;
            case GLFW_MOUSE_BUTTON_4: return MouseButtonCodes::FL_MOUSE_BUTTON_4;
            case GLFW_MOUSE_BUTTON_5: return MouseButtonCodes::FL_MOUSE_BUTTON_5;
            case GLFW_MOUSE_BUTTON_6: return MouseButtonCodes::FL_MOUSE_BUTTON_6;
            case GLFW_MOUSE_BUTTON_7: return MouseButtonCodes::FL_MOUSE_BUTTON_7;
            case GLFW_MOUSE_BUTTON_8: return MouseButtonCodes::FL_MOUSE_BUTTON_LAST;
        }
        return MouseButtonCodes::FL_MOUSE_BUTTON_UNKNOWN;
    }

    int WindowsInput::GetKeyboardKeyFromGLFW(KeyboardKeyCodes code) const
    {
        switch (code)
        {
            case KeyboardKeyCodes::FL_KEY_SPACE: return          GLFW_KEY_SPACE;
            case KeyboardKeyCodes::FL_KEY_APOSTROPHE: return     GLFW_KEY_APOSTROPHE;
            case KeyboardKeyCodes::FL_KEY_COMMA: return          GLFW_KEY_COMMA;
            case KeyboardKeyCodes::FL_KEY_MINUS: return          GLFW_KEY_MINUS;
            case KeyboardKeyCodes::FL_KEY_PERIOD: return         GLFW_KEY_PERIOD;
            case KeyboardKeyCodes::FL_KEY_SLASH: return          GLFW_KEY_SLASH;
            case KeyboardKeyCodes::FL_KEY_0: return              GLFW_KEY_0;
            case KeyboardKeyCodes::FL_KEY_1: return              GLFW_KEY_1;
            case KeyboardKeyCodes::FL_KEY_2: return              GLFW_KEY_2;
            case KeyboardKeyCodes::FL_KEY_3: return              GLFW_KEY_3;
            case KeyboardKeyCodes::FL_KEY_4: return              GLFW_KEY_4;
            case KeyboardKeyCodes::FL_KEY_5: return              GLFW_KEY_5;
            case KeyboardKeyCodes::FL_KEY_6: return              GLFW_KEY_6;
            case KeyboardKeyCodes::FL_KEY_7: return              GLFW_KEY_7;
            case KeyboardKeyCodes::FL_KEY_8: return              GLFW_KEY_8;
            case KeyboardKeyCodes::FL_KEY_9: return              GLFW_KEY_9;
            case KeyboardKeyCodes::FL_KEY_SEMICOLON: return      GLFW_KEY_SEMICOLON;
            case KeyboardKeyCodes::FL_KEY_EQUAL: return          GLFW_KEY_EQUAL;
            case KeyboardKeyCodes::FL_KEY_A: return              GLFW_KEY_A;
            case KeyboardKeyCodes::FL_KEY_B: return              GLFW_KEY_B;
            case KeyboardKeyCodes::FL_KEY_C: return              GLFW_KEY_C;
            case KeyboardKeyCodes::FL_KEY_D: return              GLFW_KEY_D;
            case KeyboardKeyCodes::FL_KEY_E: return              GLFW_KEY_E;
            case KeyboardKeyCodes::FL_KEY_F: return              GLFW_KEY_F;
            case KeyboardKeyCodes::FL_KEY_G: return              GLFW_KEY_G;
            case KeyboardKeyCodes::FL_KEY_H: return              GLFW_KEY_H;
            case KeyboardKeyCodes::FL_KEY_I: return              GLFW_KEY_I;
            case KeyboardKeyCodes::FL_KEY_J: return              GLFW_KEY_J;
            case KeyboardKeyCodes::FL_KEY_K: return              GLFW_KEY_K;
            case KeyboardKeyCodes::FL_KEY_L: return              GLFW_KEY_L;
            case KeyboardKeyCodes::FL_KEY_M: return              GLFW_KEY_M;
            case KeyboardKeyCodes::FL_KEY_N: return              GLFW_KEY_N;
            case KeyboardKeyCodes::FL_KEY_O: return              GLFW_KEY_O;
            case KeyboardKeyCodes::FL_KEY_P: return              GLFW_KEY_P;
            case KeyboardKeyCodes::FL_KEY_Q: return              GLFW_KEY_Q;
            case KeyboardKeyCodes::FL_KEY_R: return              GLFW_KEY_R;
            case KeyboardKeyCodes::FL_KEY_S: return              GLFW_KEY_S;
            case KeyboardKeyCodes::FL_KEY_T: return              GLFW_KEY_T;
            case KeyboardKeyCodes::FL_KEY_U: return              GLFW_KEY_U;
            case KeyboardKeyCodes::FL_KEY_V: return              GLFW_KEY_V;
            case KeyboardKeyCodes::FL_KEY_W: return              GLFW_KEY_W;
            case KeyboardKeyCodes::FL_KEY_X: return              GLFW_KEY_X;
            case KeyboardKeyCodes::FL_KEY_Y: return              GLFW_KEY_Y;
            case KeyboardKeyCodes::FL_KEY_Z: return              GLFW_KEY_Z;
            case KeyboardKeyCodes::FL_KEY_LEFT_BRACKET: return   GLFW_KEY_LEFT_BRACKET;
            case KeyboardKeyCodes::FL_KEY_BACKSLASH: return      GLFW_KEY_BACKSLASH;
            case KeyboardKeyCodes::FL_KEY_RIGHT_BRACKET: return  GLFW_KEY_RIGHT_BRACKET;
            case KeyboardKeyCodes::FL_KEY_GRAVE_ACCENT: return   GLFW_KEY_GRAVE_ACCENT;
            case KeyboardKeyCodes::FL_KEY_WORLD_1: return        GLFW_KEY_WORLD_1;
            case KeyboardKeyCodes::FL_KEY_WORLD_2: return        GLFW_KEY_WORLD_2;
            case KeyboardKeyCodes::FL_KEY_ESCAPE: return         GLFW_KEY_ESCAPE;
            case KeyboardKeyCodes::FL_KEY_ENTER: return          GLFW_KEY_ENTER;
            case KeyboardKeyCodes::FL_KEY_TAB: return            GLFW_KEY_TAB;
            case KeyboardKeyCodes::FL_KEY_BACKSPACE: return      GLFW_KEY_BACKSPACE;
            case KeyboardKeyCodes::FL_KEY_INSERT: return         GLFW_KEY_INSERT;
            case KeyboardKeyCodes::FL_KEY_DELETE: return         GLFW_KEY_DELETE;
            case KeyboardKeyCodes::FL_KEY_RIGHT: return          GLFW_KEY_RIGHT;
            case KeyboardKeyCodes::FL_KEY_LEFT: return           GLFW_KEY_LEFT;
            case KeyboardKeyCodes::FL_KEY_DOWN: return           GLFW_KEY_DOWN;
            case KeyboardKeyCodes::FL_KEY_UP: return             GLFW_KEY_UP;
            case KeyboardKeyCodes::FL_KEY_PAGE_UP: return        GLFW_KEY_PAGE_UP;
            case KeyboardKeyCodes::FL_KEY_PAGE_DOWN: return      GLFW_KEY_PAGE_DOWN;
            case KeyboardKeyCodes::FL_KEY_HOME: return           GLFW_KEY_HOME;
            case KeyboardKeyCodes::FL_KEY_END: return            GLFW_KEY_END;
            case KeyboardKeyCodes::FL_KEY_CAPS_LOCK: return      GLFW_KEY_CAPS_LOCK;
            case KeyboardKeyCodes::FL_KEY_SCROLL_LOCK: return    GLFW_KEY_SCROLL_LOCK;
            case KeyboardKeyCodes::FL_KEY_NUM_LOCK: return       GLFW_KEY_NUM_LOCK;
            case KeyboardKeyCodes::FL_KEY_PRINT_SCREEN: return   GLFW_KEY_PRINT_SCREEN;
            case KeyboardKeyCodes::FL_KEY_PAUSE: return          GLFW_KEY_PAUSE;
            case KeyboardKeyCodes::FL_KEY_F1: return             GLFW_KEY_F1;
            case KeyboardKeyCodes::FL_KEY_F2: return             GLFW_KEY_F2;
            case KeyboardKeyCodes::FL_KEY_F3: return             GLFW_KEY_F3;
            case KeyboardKeyCodes::FL_KEY_F4: return             GLFW_KEY_F4;
            case KeyboardKeyCodes::FL_KEY_F5: return             GLFW_KEY_F5;
            case KeyboardKeyCodes::FL_KEY_F6: return             GLFW_KEY_F6;
            case KeyboardKeyCodes::FL_KEY_F7: return             GLFW_KEY_F7;
            case KeyboardKeyCodes::FL_KEY_F8: return             GLFW_KEY_F8;
            case KeyboardKeyCodes::FL_KEY_F9: return             GLFW_KEY_F9;
            case KeyboardKeyCodes::FL_KEY_F10: return            GLFW_KEY_F10;
            case KeyboardKeyCodes::FL_KEY_F11: return            GLFW_KEY_F11;
            case KeyboardKeyCodes::FL_KEY_F12: return            GLFW_KEY_F12;
            case KeyboardKeyCodes::FL_KEY_F13: return            GLFW_KEY_F13;
            case KeyboardKeyCodes::FL_KEY_F14: return            GLFW_KEY_F14;
            case KeyboardKeyCodes::FL_KEY_F15: return            GLFW_KEY_F15;
            case KeyboardKeyCodes::FL_KEY_F16: return            GLFW_KEY_F16;
            case KeyboardKeyCodes::FL_KEY_F17: return            GLFW_KEY_F17;
            case KeyboardKeyCodes::FL_KEY_F18: return            GLFW_KEY_F18;
            case KeyboardKeyCodes::FL_KEY_F19: return            GLFW_KEY_F19;
            case KeyboardKeyCodes::FL_KEY_F20: return            GLFW_KEY_F20;
            case KeyboardKeyCodes::FL_KEY_F21: return            GLFW_KEY_F21;
            case KeyboardKeyCodes::FL_KEY_F22: return            GLFW_KEY_F22;
            case KeyboardKeyCodes::FL_KEY_F23: return            GLFW_KEY_F23;
            case KeyboardKeyCodes::FL_KEY_F24: return            GLFW_KEY_F24;
            case KeyboardKeyCodes::FL_KEY_F25: return            GLFW_KEY_F25;
            case KeyboardKeyCodes::FL_KEY_KP_0: return           GLFW_KEY_KP_0;
            case KeyboardKeyCodes::FL_KEY_KP_1: return           GLFW_KEY_KP_1;
            case KeyboardKeyCodes::FL_KEY_KP_2: return           GLFW_KEY_KP_2;
            case KeyboardKeyCodes::FL_KEY_KP_3: return           GLFW_KEY_KP_3;
            case KeyboardKeyCodes::FL_KEY_KP_4: return           GLFW_KEY_KP_4;
            case KeyboardKeyCodes::FL_KEY_KP_5: return           GLFW_KEY_KP_5;
            case KeyboardKeyCodes::FL_KEY_KP_6: return           GLFW_KEY_KP_6;
            case KeyboardKeyCodes::FL_KEY_KP_7: return           GLFW_KEY_KP_7;
            case KeyboardKeyCodes::FL_KEY_KP_8: return           GLFW_KEY_KP_8;
            case KeyboardKeyCodes::FL_KEY_KP_9: return           GLFW_KEY_KP_9;
            case KeyboardKeyCodes::FL_KEY_KP_DECIMAL: return     GLFW_KEY_KP_DECIMAL;
            case KeyboardKeyCodes::FL_KEY_KP_DIVIDE: return      GLFW_KEY_KP_DIVIDE;
            case KeyboardKeyCodes::FL_KEY_KP_MULTIPLY: return    GLFW_KEY_KP_MULTIPLY;
            case KeyboardKeyCodes::FL_KEY_KP_SUBTRACT: return    GLFW_KEY_KP_SUBTRACT;
            case KeyboardKeyCodes::FL_KEY_KP_ADD: return         GLFW_KEY_KP_ADD;
            case KeyboardKeyCodes::FL_KEY_KP_ENTER: return       GLFW_KEY_KP_ENTER;
            case KeyboardKeyCodes::FL_KEY_KP_EQUAL: return       GLFW_KEY_KP_EQUAL;
            case KeyboardKeyCodes::FL_KEY_LEFT_SHIFT: return     GLFW_KEY_LEFT_SHIFT;
            case KeyboardKeyCodes::FL_KEY_LEFT_CONTROL: return   GLFW_KEY_LEFT_CONTROL;
            case KeyboardKeyCodes::FL_KEY_LEFT_ALT: return       GLFW_KEY_LEFT_ALT;
            case KeyboardKeyCodes::FL_KEY_LEFT_SUPER: return     GLFW_KEY_LEFT_SUPER;
            case KeyboardKeyCodes::FL_KEY_RIGHT_SHIFT: return    GLFW_KEY_RIGHT_SHIFT;
            case KeyboardKeyCodes::FL_KEY_RIGHT_CONTROL: return  GLFW_KEY_RIGHT_CONTROL;
            case KeyboardKeyCodes::FL_KEY_RIGHT_ALT: return      GLFW_KEY_RIGHT_ALT;
            case KeyboardKeyCodes::FL_KEY_RIGHT_SUPER: return    GLFW_KEY_RIGHT_SUPER;
            case KeyboardKeyCodes::FL_KEY_MENU: return           GLFW_KEY_MENU;
        }
        return GLFW_KEY_UNKNOWN;
    }

    int WindowsInput::GetMouseButtonFromGLFW(MouseButtonCodes code) const
    {
        switch (code)
        {
            case MouseButtonCodes::FL_MOUSE_BUTTON_1: return          GLFW_MOUSE_BUTTON_1;
            case MouseButtonCodes::FL_MOUSE_BUTTON_2: return          GLFW_MOUSE_BUTTON_2;
            case MouseButtonCodes::FL_MOUSE_BUTTON_3: return          GLFW_MOUSE_BUTTON_3;
            case MouseButtonCodes::FL_MOUSE_BUTTON_4: return          GLFW_MOUSE_BUTTON_4;
            case MouseButtonCodes::FL_MOUSE_BUTTON_5: return          GLFW_MOUSE_BUTTON_5;
            case MouseButtonCodes::FL_MOUSE_BUTTON_6: return          GLFW_MOUSE_BUTTON_6;
            case MouseButtonCodes::FL_MOUSE_BUTTON_7: return          GLFW_MOUSE_BUTTON_7;
            case MouseButtonCodes::FL_MOUSE_BUTTON_8: return          GLFW_MOUSE_BUTTON_8;
            case MouseButtonCodes::FL_MOUSE_BUTTON_LAST: return       GLFW_MOUSE_BUTTON_LAST;
            case MouseButtonCodes::FL_MOUSE_BUTTON_LEFT: return       GLFW_MOUSE_BUTTON_LEFT;
            case MouseButtonCodes::FL_MOUSE_BUTTON_RIGHT: return      GLFW_MOUSE_BUTTON_RIGHT;
            case MouseButtonCodes::FL_MOUSE_BUTTON_MIDDLE: return     GLFW_MOUSE_BUTTON_MIDDLE;
        }
        return GLFW_KEY_UNKNOWN;
    }
}