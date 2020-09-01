#pragma once

#include <string>

namespace FarLight
{
    enum class MouseButtonCode
    {
        FL_MOUSE_BUTTON_UNKNOWN = -1,

        FL_MOUSE_BUTTON_0 = 0,
        FL_MOUSE_BUTTON_1 = 1,
        FL_MOUSE_BUTTON_2 = 2,
        FL_MOUSE_BUTTON_3 = 3,
        FL_MOUSE_BUTTON_4 = 4,
        FL_MOUSE_BUTTON_5 = 5,
        FL_MOUSE_BUTTON_6 = 6,
        FL_MOUSE_BUTTON_7 = 7,

        FL_MOUSE_BUTTON_LAST = FL_MOUSE_BUTTON_7,
        FL_MOUSE_BUTTON_LEFT = FL_MOUSE_BUTTON_0,
        FL_MOUSE_BUTTON_RIGHT = FL_MOUSE_BUTTON_1,
        FL_MOUSE_BUTTON_MIDDLE = FL_MOUSE_BUTTON_2
    };

    inline std::string FLMouseButtonCodeToString(MouseButtonCode code)
    {
        switch (code)
        {
            case MouseButtonCode::FL_MOUSE_BUTTON_0:   return "FL_MOUSE_BUTTON_0";
            case MouseButtonCode::FL_MOUSE_BUTTON_1:   return "FL_MOUSE_BUTTON_1";
            case MouseButtonCode::FL_MOUSE_BUTTON_2:   return "FL_MOUSE_BUTTON_2";
            case MouseButtonCode::FL_MOUSE_BUTTON_3:   return "FL_MOUSE_BUTTON_3";
            case MouseButtonCode::FL_MOUSE_BUTTON_4:   return "FL_MOUSE_BUTTON_4";
            case MouseButtonCode::FL_MOUSE_BUTTON_5:   return "FL_MOUSE_BUTTON_5";
            case MouseButtonCode::FL_MOUSE_BUTTON_6:   return "FL_MOUSE_BUTTON_6";
            case MouseButtonCode::FL_MOUSE_BUTTON_7:   return "FL_MOUSE_BUTTON_7";
        }
        return "FL_MOUSE_BUTTON_UNKNOWN";
    }
}
