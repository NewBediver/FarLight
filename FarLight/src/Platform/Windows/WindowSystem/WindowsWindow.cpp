// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Platform/Windows/WindowSystem/WindowsWindow.h"

#include "FarLight/InputSystem/InputManager.h"
#include "FarLight/InputSystem/KeyboardKeyCodes.h"
#include "FarLight/InputSystem/MouseButtonCodes.h"

#include "FarLight/EventSystem/WindowEvents/WindowResizedEvent.h"
#include "FarLight/EventSystem/WindowEvents/WindowClosedEvent.h"

#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyPressedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyReleasedEvent.h"
#include "FarLight/EventSystem/KeyboardEvents/KeyboardKeyTypedEvent.h"

#include "FarLight/EventSystem/MouseEvents/MouseButtonPressedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseButtonReleasedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseMovedEvent.h"
#include "FarLight/EventSystem/MouseEvents/MouseScrolledEvent.h"

#include <glad/glad.h>

namespace FarLight
{
    static bool s_IsGLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description) noexcept
    {
        FL_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    WindowsWindow::WindowsWindow(const WindowProps& props) noexcept
    {
        Init(props);
    }

    void WindowsWindow::OnUpdate() noexcept
    {
        FL_PROFILE_FUNCTION();

        glfwPollEvents();
        m_Context->SwapBuffers();
    }

    void WindowsWindow::SetVSync(bool enabled) noexcept
    {
        FL_PROFILE_FUNCTION();

        if (enabled) glfwSwapInterval(1);
        else glfwSwapInterval(0);
        m_Data.IsVSync = enabled;
    }

    void WindowsWindow::Init(const WindowProps& props) noexcept
    {
        FL_PROFILE_FUNCTION();

        m_Data.Title = props.Title;
        m_Data.Height = props.Height;
        m_Data.Width = props.Width;

        FL_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Height, m_Data.Width);

        if (!s_IsGLFWInitialized)
        {
            {
                FL_PROFILE_SCOPE("glfwInit");

                int success = glfwInit();
                FL_CORE_ASSERT(success, "Could not initialize GLFW!");
            }

            glfwSetErrorCallback(GLFWErrorCallback);
            s_IsGLFWInitialized = true;
        }

        {
            FL_PROFILE_SCOPE("glfwCreateWindow");

            m_Window = Ref<GLFWwindow>(glfwCreateWindow(static_cast<int>(m_Data.Width), static_cast<int>(m_Data.Height), m_Data.Title.c_str(), nullptr, nullptr), glfwDestroyWindow);
        }

        m_Context = CreateScope<OpenGLContext>(m_Window);
        m_Context->Init();

        glfwSetWindowUserPointer(m_Window.get(), &m_Data);
        SetVSync(true);

        SetGLFWCallbacks();
    }

    void WindowsWindow::SetGLFWCallbacks() noexcept
    {
        FL_PROFILE_FUNCTION();

        #define GET_DATA(x) *static_cast<WindowData*>(glfwGetWindowUserPointer(x));

        glfwSetWindowSizeCallback(m_Window.get(), [](GLFWwindow* win, int width, int height) {
            FL_PROFILE_FUNCTION();

            WindowData& data = GET_DATA(win);
            data.Width = width;
            data.Height = height;

            data.Callback(WindowResizedEvent(std::move(width), std::move(height)));
        });

        glfwSetWindowCloseCallback(m_Window.get(), [](GLFWwindow* win) {
            FL_PROFILE_FUNCTION();

            WindowData& data = GET_DATA(win);

            data.Callback(WindowClosedEvent());
        });

        glfwSetKeyCallback(m_Window.get(), [](GLFWwindow* win, int key, int scan, int action, int mods) {
            FL_PROFILE_FUNCTION();

            auto& getFLCode = [](int code)
            {
                switch (code)
                {
                    case GLFW_KEY_SPACE: return              KeyboardKeyCode::FL_KEY_SPACE;
                    case GLFW_KEY_APOSTROPHE: return         KeyboardKeyCode::FL_KEY_APOSTROPHE;
                    case GLFW_KEY_COMMA: return              KeyboardKeyCode::FL_KEY_COMMA;
                    case GLFW_KEY_MINUS: return              KeyboardKeyCode::FL_KEY_MINUS;
                    case GLFW_KEY_PERIOD: return             KeyboardKeyCode::FL_KEY_PERIOD;
                    case GLFW_KEY_SLASH: return              KeyboardKeyCode::FL_KEY_SLASH;
                    case GLFW_KEY_0: return                  KeyboardKeyCode::FL_KEY_0;
                    case GLFW_KEY_1: return                  KeyboardKeyCode::FL_KEY_1;
                    case GLFW_KEY_2: return                  KeyboardKeyCode::FL_KEY_2;
                    case GLFW_KEY_3: return                  KeyboardKeyCode::FL_KEY_3;
                    case GLFW_KEY_4: return                  KeyboardKeyCode::FL_KEY_4;
                    case GLFW_KEY_5: return                  KeyboardKeyCode::FL_KEY_5;
                    case GLFW_KEY_6: return                  KeyboardKeyCode::FL_KEY_6;
                    case GLFW_KEY_7: return                  KeyboardKeyCode::FL_KEY_7;
                    case GLFW_KEY_8: return                  KeyboardKeyCode::FL_KEY_8;
                    case GLFW_KEY_9: return                  KeyboardKeyCode::FL_KEY_9;
                    case GLFW_KEY_SEMICOLON: return          KeyboardKeyCode::FL_KEY_SEMICOLON;
                    case GLFW_KEY_EQUAL: return              KeyboardKeyCode::FL_KEY_EQUAL;
                    case GLFW_KEY_A: return                  KeyboardKeyCode::FL_KEY_A;
                    case GLFW_KEY_B: return                  KeyboardKeyCode::FL_KEY_B;
                    case GLFW_KEY_C: return                  KeyboardKeyCode::FL_KEY_C;
                    case GLFW_KEY_D: return                  KeyboardKeyCode::FL_KEY_D;
                    case GLFW_KEY_E: return                  KeyboardKeyCode::FL_KEY_E;
                    case GLFW_KEY_F: return                  KeyboardKeyCode::FL_KEY_F;
                    case GLFW_KEY_G: return                  KeyboardKeyCode::FL_KEY_G;
                    case GLFW_KEY_H: return                  KeyboardKeyCode::FL_KEY_H;
                    case GLFW_KEY_I: return                  KeyboardKeyCode::FL_KEY_I;
                    case GLFW_KEY_J: return                  KeyboardKeyCode::FL_KEY_J;
                    case GLFW_KEY_K: return                  KeyboardKeyCode::FL_KEY_K;
                    case GLFW_KEY_L: return                  KeyboardKeyCode::FL_KEY_L;
                    case GLFW_KEY_M: return                  KeyboardKeyCode::FL_KEY_M;
                    case GLFW_KEY_N: return                  KeyboardKeyCode::FL_KEY_N;
                    case GLFW_KEY_O: return                  KeyboardKeyCode::FL_KEY_O;
                    case GLFW_KEY_P: return                  KeyboardKeyCode::FL_KEY_P;
                    case GLFW_KEY_Q: return                  KeyboardKeyCode::FL_KEY_Q;
                    case GLFW_KEY_R: return                  KeyboardKeyCode::FL_KEY_R;
                    case GLFW_KEY_S: return                  KeyboardKeyCode::FL_KEY_S;
                    case GLFW_KEY_T: return                  KeyboardKeyCode::FL_KEY_T;
                    case GLFW_KEY_U: return                  KeyboardKeyCode::FL_KEY_U;
                    case GLFW_KEY_V: return                  KeyboardKeyCode::FL_KEY_V;
                    case GLFW_KEY_W: return                  KeyboardKeyCode::FL_KEY_W;
                    case GLFW_KEY_X: return                  KeyboardKeyCode::FL_KEY_X;
                    case GLFW_KEY_Y: return                  KeyboardKeyCode::FL_KEY_Y;
                    case GLFW_KEY_Z: return                  KeyboardKeyCode::FL_KEY_Z;
                    case GLFW_KEY_LEFT_BRACKET: return       KeyboardKeyCode::FL_KEY_LEFT_BRACKET;
                    case GLFW_KEY_BACKSLASH: return          KeyboardKeyCode::FL_KEY_BACKSLASH;
                    case GLFW_KEY_RIGHT_BRACKET: return      KeyboardKeyCode::FL_KEY_RIGHT_BRACKET;
                    case GLFW_KEY_GRAVE_ACCENT: return       KeyboardKeyCode::FL_KEY_GRAVE_ACCENT;
                    case GLFW_KEY_WORLD_1: return            KeyboardKeyCode::FL_KEY_WORLD_1;
                    case GLFW_KEY_WORLD_2: return            KeyboardKeyCode::FL_KEY_WORLD_2;
                    case GLFW_KEY_ESCAPE: return             KeyboardKeyCode::FL_KEY_ESCAPE;
                    case GLFW_KEY_ENTER: return              KeyboardKeyCode::FL_KEY_ENTER;
                    case GLFW_KEY_TAB: return                KeyboardKeyCode::FL_KEY_TAB;
                    case GLFW_KEY_BACKSPACE: return          KeyboardKeyCode::FL_KEY_BACKSPACE;
                    case GLFW_KEY_INSERT: return             KeyboardKeyCode::FL_KEY_INSERT;
                    case GLFW_KEY_DELETE: return             KeyboardKeyCode::FL_KEY_DELETE;
                    case GLFW_KEY_RIGHT: return              KeyboardKeyCode::FL_KEY_RIGHT;
                    case GLFW_KEY_LEFT: return               KeyboardKeyCode::FL_KEY_LEFT;
                    case GLFW_KEY_DOWN: return               KeyboardKeyCode::FL_KEY_DOWN;
                    case GLFW_KEY_UP: return                 KeyboardKeyCode::FL_KEY_UP;
                    case GLFW_KEY_PAGE_UP: return            KeyboardKeyCode::FL_KEY_PAGE_UP;
                    case GLFW_KEY_PAGE_DOWN: return          KeyboardKeyCode::FL_KEY_PAGE_DOWN;
                    case GLFW_KEY_HOME: return               KeyboardKeyCode::FL_KEY_HOME;
                    case GLFW_KEY_END: return                KeyboardKeyCode::FL_KEY_END;
                    case GLFW_KEY_CAPS_LOCK: return          KeyboardKeyCode::FL_KEY_CAPS_LOCK;
                    case GLFW_KEY_SCROLL_LOCK: return        KeyboardKeyCode::FL_KEY_SCROLL_LOCK;
                    case GLFW_KEY_NUM_LOCK: return           KeyboardKeyCode::FL_KEY_NUM_LOCK;
                    case GLFW_KEY_PRINT_SCREEN: return       KeyboardKeyCode::FL_KEY_PRINT_SCREEN;
                    case GLFW_KEY_PAUSE: return              KeyboardKeyCode::FL_KEY_PAUSE;
                    case GLFW_KEY_F1: return                 KeyboardKeyCode::FL_KEY_F1;
                    case GLFW_KEY_F2: return                 KeyboardKeyCode::FL_KEY_F2;
                    case GLFW_KEY_F3: return                 KeyboardKeyCode::FL_KEY_F3;
                    case GLFW_KEY_F4: return                 KeyboardKeyCode::FL_KEY_F4;
                    case GLFW_KEY_F5: return                 KeyboardKeyCode::FL_KEY_F5;
                    case GLFW_KEY_F6: return                 KeyboardKeyCode::FL_KEY_F6;
                    case GLFW_KEY_F7: return                 KeyboardKeyCode::FL_KEY_F7;
                    case GLFW_KEY_F8: return                 KeyboardKeyCode::FL_KEY_F8;
                    case GLFW_KEY_F9: return                 KeyboardKeyCode::FL_KEY_F9;
                    case GLFW_KEY_F10: return                KeyboardKeyCode::FL_KEY_F10;
                    case GLFW_KEY_F11: return                KeyboardKeyCode::FL_KEY_F11;
                    case GLFW_KEY_F12: return                KeyboardKeyCode::FL_KEY_F12;
                    case GLFW_KEY_F13: return                KeyboardKeyCode::FL_KEY_F13;
                    case GLFW_KEY_F14: return                KeyboardKeyCode::FL_KEY_F14;
                    case GLFW_KEY_F15: return                KeyboardKeyCode::FL_KEY_F15;
                    case GLFW_KEY_F16: return                KeyboardKeyCode::FL_KEY_F16;
                    case GLFW_KEY_F17: return                KeyboardKeyCode::FL_KEY_F17;
                    case GLFW_KEY_F18: return                KeyboardKeyCode::FL_KEY_F18;
                    case GLFW_KEY_F19: return                KeyboardKeyCode::FL_KEY_F19;
                    case GLFW_KEY_F20: return                KeyboardKeyCode::FL_KEY_F20;
                    case GLFW_KEY_F21: return                KeyboardKeyCode::FL_KEY_F21;
                    case GLFW_KEY_F22: return                KeyboardKeyCode::FL_KEY_F22;
                    case GLFW_KEY_F23: return                KeyboardKeyCode::FL_KEY_F23;
                    case GLFW_KEY_F24: return                KeyboardKeyCode::FL_KEY_F24;
                    case GLFW_KEY_F25: return                KeyboardKeyCode::FL_KEY_F25;
                    case GLFW_KEY_KP_0: return               KeyboardKeyCode::FL_KEY_KP_0;
                    case GLFW_KEY_KP_1: return               KeyboardKeyCode::FL_KEY_KP_1;
                    case GLFW_KEY_KP_2: return               KeyboardKeyCode::FL_KEY_KP_2;
                    case GLFW_KEY_KP_3: return               KeyboardKeyCode::FL_KEY_KP_3;
                    case GLFW_KEY_KP_4: return               KeyboardKeyCode::FL_KEY_KP_4;
                    case GLFW_KEY_KP_5: return               KeyboardKeyCode::FL_KEY_KP_5;
                    case GLFW_KEY_KP_6: return               KeyboardKeyCode::FL_KEY_KP_6;
                    case GLFW_KEY_KP_7: return               KeyboardKeyCode::FL_KEY_KP_7;
                    case GLFW_KEY_KP_8: return               KeyboardKeyCode::FL_KEY_KP_8;
                    case GLFW_KEY_KP_9: return               KeyboardKeyCode::FL_KEY_KP_9;
                    case GLFW_KEY_KP_DECIMAL: return         KeyboardKeyCode::FL_KEY_KP_DECIMAL;
                    case GLFW_KEY_KP_DIVIDE: return          KeyboardKeyCode::FL_KEY_KP_DIVIDE;
                    case GLFW_KEY_KP_MULTIPLY: return        KeyboardKeyCode::FL_KEY_KP_MULTIPLY;
                    case GLFW_KEY_KP_SUBTRACT: return        KeyboardKeyCode::FL_KEY_KP_SUBTRACT;
                    case GLFW_KEY_KP_ADD: return             KeyboardKeyCode::FL_KEY_KP_ADD;
                    case GLFW_KEY_KP_ENTER: return           KeyboardKeyCode::FL_KEY_KP_ENTER;
                    case GLFW_KEY_KP_EQUAL: return           KeyboardKeyCode::FL_KEY_KP_EQUAL;
                    case GLFW_KEY_LEFT_SHIFT: return         KeyboardKeyCode::FL_KEY_LEFT_SHIFT;
                    case GLFW_KEY_LEFT_CONTROL: return       KeyboardKeyCode::FL_KEY_LEFT_CONTROL;
                    case GLFW_KEY_LEFT_ALT: return           KeyboardKeyCode::FL_KEY_LEFT_ALT;
                    case GLFW_KEY_LEFT_SUPER: return         KeyboardKeyCode::FL_KEY_LEFT_SUPER;
                    case GLFW_KEY_RIGHT_SHIFT: return        KeyboardKeyCode::FL_KEY_RIGHT_SHIFT;
                    case GLFW_KEY_RIGHT_CONTROL: return      KeyboardKeyCode::FL_KEY_RIGHT_CONTROL;
                    case GLFW_KEY_RIGHT_ALT: return          KeyboardKeyCode::FL_KEY_RIGHT_ALT;
                    case GLFW_KEY_RIGHT_SUPER: return        KeyboardKeyCode::FL_KEY_RIGHT_SUPER;
                    case GLFW_KEY_MENU: return               KeyboardKeyCode::FL_KEY_MENU;
                }
                return KeyboardKeyCode::FL_KEY_UNKNOWN;
            };

            WindowData& data = GET_DATA(win);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    data.Callback(KeyboardKeyPressedEvent(std::move(getFLCode(key)), false));
                    break;
                }
                case GLFW_RELEASE:
                {
                    data.Callback(KeyboardKeyReleasedEvent(std::move(getFLCode(key))));
                    break;
                }
                case GLFW_REPEAT:
                {
                    data.Callback(KeyboardKeyPressedEvent(std::move(getFLCode(key)), true));
                    break;
                }
            }
        });

        glfwSetCharCallback(m_Window.get(), [](GLFWwindow* win, unsigned code) {
            FL_PROFILE_FUNCTION();

            WindowData& data = GET_DATA(win);

            data.Callback(KeyboardKeyTypedEvent(std::move(code)));
        });

        glfwSetMouseButtonCallback(m_Window.get(), [](GLFWwindow* win, int button, int action, int mods) {
            FL_PROFILE_FUNCTION();

            auto& getFLCode = [](int code)
            {
                switch (code)
                {
                    case GLFW_MOUSE_BUTTON_1: return MouseButtonCode::FL_MOUSE_BUTTON_0;
                    case GLFW_MOUSE_BUTTON_2: return MouseButtonCode::FL_MOUSE_BUTTON_1;
                    case GLFW_MOUSE_BUTTON_3: return MouseButtonCode::FL_MOUSE_BUTTON_2;
                    case GLFW_MOUSE_BUTTON_4: return MouseButtonCode::FL_MOUSE_BUTTON_3;
                    case GLFW_MOUSE_BUTTON_5: return MouseButtonCode::FL_MOUSE_BUTTON_4;
                    case GLFW_MOUSE_BUTTON_6: return MouseButtonCode::FL_MOUSE_BUTTON_5;
                    case GLFW_MOUSE_BUTTON_7: return MouseButtonCode::FL_MOUSE_BUTTON_6;
                    case GLFW_MOUSE_BUTTON_8: return MouseButtonCode::FL_MOUSE_BUTTON_7;
                }
                return MouseButtonCode::FL_MOUSE_BUTTON_UNKNOWN;
            };

            WindowData& data = GET_DATA(win);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    data.Callback(MouseButtonPressedEvent(std::move(getFLCode(button))));
                    break;
                }
                case GLFW_RELEASE:
                {
                    data.Callback(MouseButtonReleasedEvent(std::move(getFLCode(button))));
                    break;
                }
            }
        });

        glfwSetScrollCallback(m_Window.get(), [](GLFWwindow* win, double xOffset, double yOffset) {
            FL_PROFILE_FUNCTION();

            WindowData& data = GET_DATA(win);

            data.Callback(MouseScrolledEvent(std::move(xOffset), std::move(yOffset)));
        });

        glfwSetCursorPosCallback(m_Window.get(), [](GLFWwindow* win, double xPos, double yPos) {
            FL_PROFILE_FUNCTION();

            WindowData& data = GET_DATA(win);

            data.Callback(MouseMovedEvent(std::move(xPos), std::move(yPos)));
        });
    }
}
