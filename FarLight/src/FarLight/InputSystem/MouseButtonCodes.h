#pragma once

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
}
