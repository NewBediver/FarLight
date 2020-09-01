#pragma once

#include <string>

namespace FarLight
{
    enum class KeyboardKeyCode
    {
        FL_KEY_UNKNOWN = -1,

        FL_KEY_SPACE = 32,
        FL_KEY_APOSTROPHE = 39,  /* ' */
        FL_KEY_COMMA = 44,  /* , */
        FL_KEY_MINUS = 45,  /* - */
        FL_KEY_PERIOD = 46,  /* . */
        FL_KEY_SLASH = 47,  /* / */

        /* Digits */
        FL_KEY_0 = 48,
        FL_KEY_1 = 49,
        FL_KEY_2 = 50,
        FL_KEY_3 = 51,
        FL_KEY_4 = 52,
        FL_KEY_5 = 53,
        FL_KEY_6 = 54,
        FL_KEY_7 = 55,
        FL_KEY_8 = 56,
        FL_KEY_9 = 57,

        FL_KEY_SEMICOLON = 59,  /* ; */
        FL_KEY_EQUAL = 61,  /* = */

        /* Letters */
        FL_KEY_A = 65,
        FL_KEY_B = 66,
        FL_KEY_C = 67,
        FL_KEY_D = 68,
        FL_KEY_E = 69,
        FL_KEY_F = 70,
        FL_KEY_G = 71,
        FL_KEY_H = 72,
        FL_KEY_I = 73,
        FL_KEY_J = 74,
        FL_KEY_K = 75,
        FL_KEY_L = 76,
        FL_KEY_M = 77,
        FL_KEY_N = 78,
        FL_KEY_O = 79,
        FL_KEY_P = 80,
        FL_KEY_Q = 81,
        FL_KEY_R = 82,
        FL_KEY_S = 83,
        FL_KEY_T = 84,
        FL_KEY_U = 85,
        FL_KEY_V = 86,
        FL_KEY_W = 87,
        FL_KEY_X = 88,
        FL_KEY_Y = 89,
        FL_KEY_Z = 90,

        FL_KEY_LEFT_BRACKET = 91,  /* [ */
        FL_KEY_BACKSLASH = 92,  /* \ */
        FL_KEY_RIGHT_BRACKET = 93,  /* ] */
        FL_KEY_GRAVE_ACCENT = 96,  /* ` */
        FL_KEY_WORLD_1 = 161, /* non-US #1 */
        FL_KEY_WORLD_2 = 162, /* non-US #2 */

        /* Function keys */
        FL_KEY_ESCAPE = 256,
        FL_KEY_ENTER = 257,
        FL_KEY_TAB = 258,
        FL_KEY_BACKSPACE = 259,
        FL_KEY_INSERT = 260,
        FL_KEY_DELETE = 261,
        FL_KEY_RIGHT = 262,
        FL_KEY_LEFT = 263,
        FL_KEY_DOWN = 264,
        FL_KEY_UP = 265,
        FL_KEY_PAGE_UP = 266,
        FL_KEY_PAGE_DOWN = 267,
        FL_KEY_HOME = 268,
        FL_KEY_END = 269,
        FL_KEY_CAPS_LOCK = 280,
        FL_KEY_SCROLL_LOCK = 281,
        FL_KEY_NUM_LOCK = 282,
        FL_KEY_PRINT_SCREEN = 283,
        FL_KEY_PAUSE = 284,
        FL_KEY_F1 = 290,
        FL_KEY_F2 = 291,
        FL_KEY_F3 = 292,
        FL_KEY_F4 = 293,
        FL_KEY_F5 = 294,
        FL_KEY_F6 = 295,
        FL_KEY_F7 = 296,
        FL_KEY_F8 = 297,
        FL_KEY_F9 = 298,
        FL_KEY_F10 = 299,
        FL_KEY_F11 = 300,
        FL_KEY_F12 = 301,
        FL_KEY_F13 = 302,
        FL_KEY_F14 = 303,
        FL_KEY_F15 = 304,
        FL_KEY_F16 = 305,
        FL_KEY_F17 = 306,
        FL_KEY_F18 = 307,
        FL_KEY_F19 = 308,
        FL_KEY_F20 = 309,
        FL_KEY_F21 = 310,
        FL_KEY_F22 = 311,
        FL_KEY_F23 = 312,
        FL_KEY_F24 = 313,
        FL_KEY_F25 = 314,
        FL_KEY_KP_0 = 320,
        FL_KEY_KP_1 = 321,
        FL_KEY_KP_2 = 322,
        FL_KEY_KP_3 = 323,
        FL_KEY_KP_4 = 324,
        FL_KEY_KP_5 = 325,
        FL_KEY_KP_6 = 326,
        FL_KEY_KP_7 = 327,
        FL_KEY_KP_8 = 328,
        FL_KEY_KP_9 = 329,
        FL_KEY_KP_DECIMAL = 330,
        FL_KEY_KP_DIVIDE = 331,
        FL_KEY_KP_MULTIPLY = 332,
        FL_KEY_KP_SUBTRACT = 333,
        FL_KEY_KP_ADD = 334,
        FL_KEY_KP_ENTER = 335,
        FL_KEY_KP_EQUAL = 336,
        FL_KEY_LEFT_SHIFT = 340,
        FL_KEY_LEFT_CONTROL = 341,
        FL_KEY_LEFT_ALT = 342,
        FL_KEY_LEFT_SUPER = 343,
        FL_KEY_RIGHT_SHIFT = 344,
        FL_KEY_RIGHT_CONTROL = 345,
        FL_KEY_RIGHT_ALT = 346,
        FL_KEY_RIGHT_SUPER = 347,
        FL_KEY_MENU = 348
    };

    inline std::string FLKeyboardKeyCodeToString(KeyboardKeyCode code)
    {
        switch (code)
        {
            case KeyboardKeyCode::FL_KEY_SPACE:          return "FL_KEY_SPACE";
            case KeyboardKeyCode::FL_KEY_APOSTROPHE:     return "FL_KEY_APOSTROPHE";
            case KeyboardKeyCode::FL_KEY_COMMA:          return "FL_KEY_COMMA";
            case KeyboardKeyCode::FL_KEY_MINUS:          return "FL_KEY_MINUS";
            case KeyboardKeyCode::FL_KEY_PERIOD:         return "FL_KEY_PERIOD";
            case KeyboardKeyCode::FL_KEY_SLASH:          return "FL_KEY_SLASH";
            case KeyboardKeyCode::FL_KEY_0:              return "FL_KEY_0";
            case KeyboardKeyCode::FL_KEY_1:              return "FL_KEY_1";
            case KeyboardKeyCode::FL_KEY_2:              return "FL_KEY_2";
            case KeyboardKeyCode::FL_KEY_3:              return "FL_KEY_3";
            case KeyboardKeyCode::FL_KEY_4:              return "FL_KEY_4";
            case KeyboardKeyCode::FL_KEY_5:              return "FL_KEY_5";
            case KeyboardKeyCode::FL_KEY_6:              return "FL_KEY_6";
            case KeyboardKeyCode::FL_KEY_7:              return "FL_KEY_7";
            case KeyboardKeyCode::FL_KEY_8:              return "FL_KEY_8";
            case KeyboardKeyCode::FL_KEY_9:              return "FL_KEY_9";
            case KeyboardKeyCode::FL_KEY_SEMICOLON:      return "FL_KEY_SEMICOLON";
            case KeyboardKeyCode::FL_KEY_EQUAL:          return "FL_KEY_EQUAL";
            case KeyboardKeyCode::FL_KEY_A:              return "FL_KEY_A";
            case KeyboardKeyCode::FL_KEY_B:              return "FL_KEY_B";
            case KeyboardKeyCode::FL_KEY_C:              return "FL_KEY_C";
            case KeyboardKeyCode::FL_KEY_D:              return "FL_KEY_D";
            case KeyboardKeyCode::FL_KEY_E:              return "FL_KEY_E";
            case KeyboardKeyCode::FL_KEY_F:              return "FL_KEY_F";
            case KeyboardKeyCode::FL_KEY_G:              return "FL_KEY_G";
            case KeyboardKeyCode::FL_KEY_H:              return "FL_KEY_H";
            case KeyboardKeyCode::FL_KEY_I:              return "FL_KEY_I";
            case KeyboardKeyCode::FL_KEY_J:              return "FL_KEY_J";
            case KeyboardKeyCode::FL_KEY_K:              return "FL_KEY_K";
            case KeyboardKeyCode::FL_KEY_L:              return "FL_KEY_L";
            case KeyboardKeyCode::FL_KEY_M:              return "FL_KEY_M";
            case KeyboardKeyCode::FL_KEY_N:              return "FL_KEY_N";
            case KeyboardKeyCode::FL_KEY_O:              return "FL_KEY_O";
            case KeyboardKeyCode::FL_KEY_P:              return "FL_KEY_P";
            case KeyboardKeyCode::FL_KEY_Q:              return "FL_KEY_Q";
            case KeyboardKeyCode::FL_KEY_R:              return "FL_KEY_R";
            case KeyboardKeyCode::FL_KEY_S:              return "FL_KEY_S";
            case KeyboardKeyCode::FL_KEY_T:              return "FL_KEY_T";
            case KeyboardKeyCode::FL_KEY_U:              return "FL_KEY_U";
            case KeyboardKeyCode::FL_KEY_V:              return "FL_KEY_V";
            case KeyboardKeyCode::FL_KEY_W:              return "FL_KEY_W";
            case KeyboardKeyCode::FL_KEY_X:              return "FL_KEY_X";
            case KeyboardKeyCode::FL_KEY_Y:              return "FL_KEY_Y";
            case KeyboardKeyCode::FL_KEY_Z:              return "FL_KEY_Z";
            case KeyboardKeyCode::FL_KEY_LEFT_BRACKET:   return "FL_KEY_LEFT_BRACKET";
            case KeyboardKeyCode::FL_KEY_BACKSLASH:      return "FL_KEY_BACKSLASH";
            case KeyboardKeyCode::FL_KEY_RIGHT_BRACKET:  return "FL_KEY_RIGHT_BRACKET";
            case KeyboardKeyCode::FL_KEY_GRAVE_ACCENT:   return "FL_KEY_GRAVE_ACCENT";
            case KeyboardKeyCode::FL_KEY_WORLD_1:        return "FL_KEY_WORLD_1";
            case KeyboardKeyCode::FL_KEY_WORLD_2:        return "FL_KEY_WORLD_2";
            case KeyboardKeyCode::FL_KEY_ESCAPE:         return "FL_KEY_ESCAPE";
            case KeyboardKeyCode::FL_KEY_ENTER:          return "FL_KEY_ENTER";
            case KeyboardKeyCode::FL_KEY_TAB:            return "FL_KEY_TAB";
            case KeyboardKeyCode::FL_KEY_BACKSPACE:      return "FL_KEY_BACKSPACE";
            case KeyboardKeyCode::FL_KEY_INSERT:         return "FL_KEY_INSERT";
            case KeyboardKeyCode::FL_KEY_DELETE:         return "FL_KEY_DELETE";
            case KeyboardKeyCode::FL_KEY_RIGHT:          return "FL_KEY_RIGHT";
            case KeyboardKeyCode::FL_KEY_LEFT:           return "FL_KEY_LEFT";
            case KeyboardKeyCode::FL_KEY_DOWN:           return "FL_KEY_DOWN";
            case KeyboardKeyCode::FL_KEY_UP:             return "FL_KEY_UP";
            case KeyboardKeyCode::FL_KEY_PAGE_UP:        return "FL_KEY_PAGE_UP";
            case KeyboardKeyCode::FL_KEY_PAGE_DOWN:      return "FL_KEY_PAGE_DOWN";
            case KeyboardKeyCode::FL_KEY_HOME:           return "FL_KEY_HOME";
            case KeyboardKeyCode::FL_KEY_END:            return "FL_KEY_END";
            case KeyboardKeyCode::FL_KEY_CAPS_LOCK:      return "FL_KEY_CAPS_LOCK";
            case KeyboardKeyCode::FL_KEY_SCROLL_LOCK:    return "FL_KEY_SCROLL_LOCK";
            case KeyboardKeyCode::FL_KEY_NUM_LOCK:       return "FL_KEY_NUM_LOCK";
            case KeyboardKeyCode::FL_KEY_PRINT_SCREEN:   return "FL_KEY_PRINT_SCREEN";
            case KeyboardKeyCode::FL_KEY_PAUSE:          return "FL_KEY_PAUSE";
            case KeyboardKeyCode::FL_KEY_F1:             return "FL_KEY_F1";
            case KeyboardKeyCode::FL_KEY_F2:             return "FL_KEY_F2";
            case KeyboardKeyCode::FL_KEY_F3:             return "FL_KEY_F3";
            case KeyboardKeyCode::FL_KEY_F4:             return "FL_KEY_F4";
            case KeyboardKeyCode::FL_KEY_F5:             return "FL_KEY_F5";
            case KeyboardKeyCode::FL_KEY_F6:             return "FL_KEY_F6";
            case KeyboardKeyCode::FL_KEY_F7:             return "FL_KEY_F7";
            case KeyboardKeyCode::FL_KEY_F8:             return "FL_KEY_F8";
            case KeyboardKeyCode::FL_KEY_F9:             return "FL_KEY_F9";
            case KeyboardKeyCode::FL_KEY_F10:            return "FL_KEY_F10";
            case KeyboardKeyCode::FL_KEY_F11:            return "FL_KEY_F11";
            case KeyboardKeyCode::FL_KEY_F12:            return "FL_KEY_F12";
            case KeyboardKeyCode::FL_KEY_F13:            return "FL_KEY_F13";
            case KeyboardKeyCode::FL_KEY_F14:            return "FL_KEY_F14";
            case KeyboardKeyCode::FL_KEY_F15:            return "FL_KEY_F15";
            case KeyboardKeyCode::FL_KEY_F16:            return "FL_KEY_F16";
            case KeyboardKeyCode::FL_KEY_F17:            return "FL_KEY_F17";
            case KeyboardKeyCode::FL_KEY_F18:            return "FL_KEY_F18";
            case KeyboardKeyCode::FL_KEY_F19:            return "FL_KEY_F19";
            case KeyboardKeyCode::FL_KEY_F20:            return "FL_KEY_F20";
            case KeyboardKeyCode::FL_KEY_F21:            return "FL_KEY_F21";
            case KeyboardKeyCode::FL_KEY_F22:            return "FL_KEY_F22";
            case KeyboardKeyCode::FL_KEY_F23:            return "FL_KEY_F23";
            case KeyboardKeyCode::FL_KEY_F24:            return "FL_KEY_F24";
            case KeyboardKeyCode::FL_KEY_F25:            return "FL_KEY_F25";
            case KeyboardKeyCode::FL_KEY_KP_0:           return "FL_KEY_KP_0";
            case KeyboardKeyCode::FL_KEY_KP_1:           return "FL_KEY_KP_1";
            case KeyboardKeyCode::FL_KEY_KP_2:           return "FL_KEY_KP_2";
            case KeyboardKeyCode::FL_KEY_KP_3:           return "FL_KEY_KP_3";
            case KeyboardKeyCode::FL_KEY_KP_4:           return "FL_KEY_KP_4";
            case KeyboardKeyCode::FL_KEY_KP_5:           return "FL_KEY_KP_5";
            case KeyboardKeyCode::FL_KEY_KP_6:           return "FL_KEY_KP_6";
            case KeyboardKeyCode::FL_KEY_KP_7:           return "FL_KEY_KP_7";
            case KeyboardKeyCode::FL_KEY_KP_8:           return "FL_KEY_KP_8";
            case KeyboardKeyCode::FL_KEY_KP_9:           return "FL_KEY_KP_9";
            case KeyboardKeyCode::FL_KEY_KP_DECIMAL:     return "FL_KEY_KP_DECIMAL";
            case KeyboardKeyCode::FL_KEY_KP_DIVIDE:      return "FL_KEY_KP_DIVIDE";
            case KeyboardKeyCode::FL_KEY_KP_MULTIPLY:    return "FL_KEY_KP_MULTIPLY";
            case KeyboardKeyCode::FL_KEY_KP_SUBTRACT:    return "FL_KEY_KP_SUBTRACT";
            case KeyboardKeyCode::FL_KEY_KP_ADD:         return "FL_KEY_KP_ADD";
            case KeyboardKeyCode::FL_KEY_KP_ENTER:       return "FL_KEY_KP_ENTER";
            case KeyboardKeyCode::FL_KEY_KP_EQUAL:       return "FL_KEY_KP_EQUAL";
            case KeyboardKeyCode::FL_KEY_LEFT_SHIFT:     return "FL_KEY_LEFT_SHIFT";
            case KeyboardKeyCode::FL_KEY_LEFT_CONTROL:   return "FL_KEY_LEFT_CONTROL";
            case KeyboardKeyCode::FL_KEY_LEFT_ALT:       return "FL_KEY_LEFT_ALT";
            case KeyboardKeyCode::FL_KEY_LEFT_SUPER:     return "FL_KEY_LEFT_SUPER";
            case KeyboardKeyCode::FL_KEY_RIGHT_SHIFT:    return "FL_KEY_RIGHT_SHIFT";
            case KeyboardKeyCode::FL_KEY_RIGHT_CONTROL:  return "FL_KEY_RIGHT_CONTROL";
            case KeyboardKeyCode::FL_KEY_RIGHT_ALT:      return "FL_KEY_RIGHT_ALT";
            case KeyboardKeyCode::FL_KEY_RIGHT_SUPER:    return "FL_KEY_RIGHT_SUPER";
            case KeyboardKeyCode::FL_KEY_MENU:           return "FL_KEY_MENU";
        }
        return "FL_KEY_UNKNOWN";
    }
}
