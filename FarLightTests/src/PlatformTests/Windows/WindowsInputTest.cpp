#include <gtest/gtest.h>
#include <Platform/Windows/InputSystem/WindowsInput.h>

using namespace FarLight;

class WindowsInputTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		w = new WindowsInput();
	}

	void TearDown() override
	{
		delete w;
	}

	WindowsInput* w;
};

TEST_F(WindowsInputTest, GetFLKeyboardKeyCodeImpl)
{
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_SPACE), KeyboardKeyCodes::FL_KEY_SPACE);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_APOSTROPHE), KeyboardKeyCodes::FL_KEY_APOSTROPHE);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_COMMA), KeyboardKeyCodes::FL_KEY_COMMA);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_MINUS), KeyboardKeyCodes::FL_KEY_MINUS);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_PERIOD), KeyboardKeyCodes::FL_KEY_PERIOD);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_SLASH), KeyboardKeyCodes::FL_KEY_SLASH);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_0), KeyboardKeyCodes::FL_KEY_0);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_1), KeyboardKeyCodes::FL_KEY_1);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_2), KeyboardKeyCodes::FL_KEY_2);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_3), KeyboardKeyCodes::FL_KEY_3);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_4), KeyboardKeyCodes::FL_KEY_4);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_5), KeyboardKeyCodes::FL_KEY_5);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_6), KeyboardKeyCodes::FL_KEY_6);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_7), KeyboardKeyCodes::FL_KEY_7);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_8), KeyboardKeyCodes::FL_KEY_8);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_9), KeyboardKeyCodes::FL_KEY_9);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_SEMICOLON), KeyboardKeyCodes::FL_KEY_SEMICOLON);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_EQUAL), KeyboardKeyCodes::FL_KEY_EQUAL);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_A), KeyboardKeyCodes::FL_KEY_A);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_B), KeyboardKeyCodes::FL_KEY_B);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_C), KeyboardKeyCodes::FL_KEY_C);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_D), KeyboardKeyCodes::FL_KEY_D);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_E), KeyboardKeyCodes::FL_KEY_E);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F), KeyboardKeyCodes::FL_KEY_F);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_G), KeyboardKeyCodes::FL_KEY_G);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_H), KeyboardKeyCodes::FL_KEY_H);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_I), KeyboardKeyCodes::FL_KEY_I);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_J), KeyboardKeyCodes::FL_KEY_J);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_K), KeyboardKeyCodes::FL_KEY_K);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_L), KeyboardKeyCodes::FL_KEY_L);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_M), KeyboardKeyCodes::FL_KEY_M);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_N), KeyboardKeyCodes::FL_KEY_N);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_O), KeyboardKeyCodes::FL_KEY_O);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_P), KeyboardKeyCodes::FL_KEY_P);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_Q), KeyboardKeyCodes::FL_KEY_Q);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_R), KeyboardKeyCodes::FL_KEY_R);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_S), KeyboardKeyCodes::FL_KEY_S);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_T), KeyboardKeyCodes::FL_KEY_T);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_U), KeyboardKeyCodes::FL_KEY_U);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_V), KeyboardKeyCodes::FL_KEY_V);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_W), KeyboardKeyCodes::FL_KEY_W);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_X), KeyboardKeyCodes::FL_KEY_X);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_Y), KeyboardKeyCodes::FL_KEY_Y);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_Z), KeyboardKeyCodes::FL_KEY_Z);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_LEFT_BRACKET), KeyboardKeyCodes::FL_KEY_LEFT_BRACKET);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_BACKSLASH), KeyboardKeyCodes::FL_KEY_BACKSLASH);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_RIGHT_BRACKET), KeyboardKeyCodes::FL_KEY_RIGHT_BRACKET);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_GRAVE_ACCENT), KeyboardKeyCodes::FL_KEY_GRAVE_ACCENT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_WORLD_1), KeyboardKeyCodes::FL_KEY_WORLD_1);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_WORLD_2), KeyboardKeyCodes::FL_KEY_WORLD_2);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_ESCAPE), KeyboardKeyCodes::FL_KEY_ESCAPE);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_ENTER), KeyboardKeyCodes::FL_KEY_ENTER);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_TAB), KeyboardKeyCodes::FL_KEY_TAB);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_BACKSPACE), KeyboardKeyCodes::FL_KEY_BACKSPACE);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_INSERT), KeyboardKeyCodes::FL_KEY_INSERT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_DELETE), KeyboardKeyCodes::FL_KEY_DELETE);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_RIGHT), KeyboardKeyCodes::FL_KEY_RIGHT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_LEFT), KeyboardKeyCodes::FL_KEY_LEFT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_DOWN), KeyboardKeyCodes::FL_KEY_DOWN);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_UP), KeyboardKeyCodes::FL_KEY_UP);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_PAGE_UP), KeyboardKeyCodes::FL_KEY_PAGE_UP);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_PAGE_DOWN), KeyboardKeyCodes::FL_KEY_PAGE_DOWN);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_HOME), KeyboardKeyCodes::FL_KEY_HOME);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_END), KeyboardKeyCodes::FL_KEY_END);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_CAPS_LOCK), KeyboardKeyCodes::FL_KEY_CAPS_LOCK);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_SCROLL_LOCK), KeyboardKeyCodes::FL_KEY_SCROLL_LOCK);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_NUM_LOCK), KeyboardKeyCodes::FL_KEY_NUM_LOCK);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_PRINT_SCREEN), KeyboardKeyCodes::FL_KEY_PRINT_SCREEN);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_PAUSE), KeyboardKeyCodes::FL_KEY_PAUSE);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F1), KeyboardKeyCodes::FL_KEY_F1);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F2), KeyboardKeyCodes::FL_KEY_F2);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F3), KeyboardKeyCodes::FL_KEY_F3);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F4), KeyboardKeyCodes::FL_KEY_F4);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F5), KeyboardKeyCodes::FL_KEY_F5);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F6), KeyboardKeyCodes::FL_KEY_F6);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F7), KeyboardKeyCodes::FL_KEY_F7);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F8), KeyboardKeyCodes::FL_KEY_F8);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F9), KeyboardKeyCodes::FL_KEY_F9);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F10), KeyboardKeyCodes::FL_KEY_F10);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F11), KeyboardKeyCodes::FL_KEY_F11);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F12), KeyboardKeyCodes::FL_KEY_F12);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F13), KeyboardKeyCodes::FL_KEY_F13);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F14), KeyboardKeyCodes::FL_KEY_F14);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F15), KeyboardKeyCodes::FL_KEY_F15);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F16), KeyboardKeyCodes::FL_KEY_F16);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F17), KeyboardKeyCodes::FL_KEY_F17);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F18), KeyboardKeyCodes::FL_KEY_F18);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F19), KeyboardKeyCodes::FL_KEY_F19);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F20), KeyboardKeyCodes::FL_KEY_F20);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F21), KeyboardKeyCodes::FL_KEY_F21);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F22), KeyboardKeyCodes::FL_KEY_F22);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F23), KeyboardKeyCodes::FL_KEY_F23);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F24), KeyboardKeyCodes::FL_KEY_F24);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_F25), KeyboardKeyCodes::FL_KEY_F25);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_0), KeyboardKeyCodes::FL_KEY_KP_0);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_1), KeyboardKeyCodes::FL_KEY_KP_1);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_2), KeyboardKeyCodes::FL_KEY_KP_2);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_3), KeyboardKeyCodes::FL_KEY_KP_3);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_4), KeyboardKeyCodes::FL_KEY_KP_4);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_5), KeyboardKeyCodes::FL_KEY_KP_5);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_6), KeyboardKeyCodes::FL_KEY_KP_6);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_7), KeyboardKeyCodes::FL_KEY_KP_7);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_8), KeyboardKeyCodes::FL_KEY_KP_8);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_9), KeyboardKeyCodes::FL_KEY_KP_9);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_DECIMAL), KeyboardKeyCodes::FL_KEY_KP_DECIMAL);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_DIVIDE), KeyboardKeyCodes::FL_KEY_KP_DIVIDE);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_MULTIPLY), KeyboardKeyCodes::FL_KEY_KP_MULTIPLY);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_SUBTRACT), KeyboardKeyCodes::FL_KEY_KP_SUBTRACT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_ADD), KeyboardKeyCodes::FL_KEY_KP_ADD);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_ENTER), KeyboardKeyCodes::FL_KEY_KP_ENTER);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_KP_EQUAL), KeyboardKeyCodes::FL_KEY_KP_EQUAL);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_LEFT_SHIFT), KeyboardKeyCodes::FL_KEY_LEFT_SHIFT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_LEFT_CONTROL), KeyboardKeyCodes::FL_KEY_LEFT_CONTROL);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_LEFT_ALT), KeyboardKeyCodes::FL_KEY_LEFT_ALT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_LEFT_SUPER), KeyboardKeyCodes::FL_KEY_LEFT_SUPER);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_RIGHT_SHIFT), KeyboardKeyCodes::FL_KEY_RIGHT_SHIFT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_RIGHT_CONTROL), KeyboardKeyCodes::FL_KEY_RIGHT_CONTROL);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_RIGHT_ALT), KeyboardKeyCodes::FL_KEY_RIGHT_ALT);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_RIGHT_SUPER), KeyboardKeyCodes::FL_KEY_RIGHT_SUPER);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(GLFW_KEY_MENU), KeyboardKeyCodes::FL_KEY_MENU);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(-1), KeyboardKeyCodes::FL_KEY_UNKNOWN);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(1000), KeyboardKeyCodes::FL_KEY_UNKNOWN);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(45245), KeyboardKeyCodes::FL_KEY_UNKNOWN);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(34537), KeyboardKeyCodes::FL_KEY_UNKNOWN);
    EXPECT_EQ(w->GetFLKeyboardKeyCodeImpl(135453), KeyboardKeyCodes::FL_KEY_UNKNOWN);
}

TEST_F(WindowsInputTest, GetFLMouseButtonCodeImpl)
{
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_1), MouseButtonCodes::FL_MOUSE_BUTTON_LEFT);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_2), MouseButtonCodes::FL_MOUSE_BUTTON_RIGHT);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_3), MouseButtonCodes::FL_MOUSE_BUTTON_MIDDLE);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_4), MouseButtonCodes::FL_MOUSE_BUTTON_4);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_5), MouseButtonCodes::FL_MOUSE_BUTTON_5);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_6), MouseButtonCodes::FL_MOUSE_BUTTON_6);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_7), MouseButtonCodes::FL_MOUSE_BUTTON_7);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_8), MouseButtonCodes::FL_MOUSE_BUTTON_LAST);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_LAST), MouseButtonCodes::FL_MOUSE_BUTTON_LAST);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_LEFT), MouseButtonCodes::FL_MOUSE_BUTTON_LEFT);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_RIGHT), MouseButtonCodes::FL_MOUSE_BUTTON_RIGHT);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(GLFW_MOUSE_BUTTON_MIDDLE), MouseButtonCodes::FL_MOUSE_BUTTON_MIDDLE);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(-1), MouseButtonCodes::FL_MOUSE_BUTTON_UNKNOWN);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(15), MouseButtonCodes::FL_MOUSE_BUTTON_UNKNOWN);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(11), MouseButtonCodes::FL_MOUSE_BUTTON_UNKNOWN);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(75), MouseButtonCodes::FL_MOUSE_BUTTON_UNKNOWN);
    EXPECT_EQ(w->GetFLMouseButtonCodeImpl(12), MouseButtonCodes::FL_MOUSE_BUTTON_UNKNOWN);
}