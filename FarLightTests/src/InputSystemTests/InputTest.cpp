#include <gtest/gtest.h>
#include <FarLight/InputSystem/Input.h>

using namespace FarLight;

class ExampleTestInput
	: public Input
{
protected:
	virtual bool IsKeyPressedImpl(KeyboardKeyCodes code) const override { return code == KeyboardKeyCodes::FL_KEY_ENTER; }
	virtual bool IsMouseButtonPressedImpl(MouseButtonCodes code) const override { return code == MouseButtonCodes::FL_MOUSE_BUTTON_LEFT; }
	virtual std::pair<double, double> GetMousePositionImpl() const override { return { 0.5, 10.35 }; }
	virtual double GetMouseXImpl() const override { return GetMousePositionImpl().first; }
	virtual double GetMouseYImpl() const override { return GetMousePositionImpl().second; }

	virtual KeyboardKeyCodes GetFLKeyboardKeyCodeImpl(int code) const override
	{
		switch (code)
		{
			case 32: return KeyboardKeyCodes::FL_KEY_SPACE;
			case 39: return KeyboardKeyCodes::FL_KEY_APOSTROPHE;
			case 44: return KeyboardKeyCodes::FL_KEY_COMMA;
			case 45: return KeyboardKeyCodes::FL_KEY_MINUS;
			case 46: return KeyboardKeyCodes::FL_KEY_PERIOD;
			case 47: return KeyboardKeyCodes::FL_KEY_SLASH;
			case 48: return KeyboardKeyCodes::FL_KEY_0;
			case 49: return KeyboardKeyCodes::FL_KEY_1;
			case 50: return KeyboardKeyCodes::FL_KEY_2;
			case 51: return KeyboardKeyCodes::FL_KEY_3;
			case 52: return KeyboardKeyCodes::FL_KEY_4;
			case 53: return KeyboardKeyCodes::FL_KEY_5;
			case 54: return KeyboardKeyCodes::FL_KEY_6;
			case 55: return KeyboardKeyCodes::FL_KEY_7;
			case 56: return KeyboardKeyCodes::FL_KEY_8;
			case 57: return KeyboardKeyCodes::FL_KEY_9;
			case 59: return KeyboardKeyCodes::FL_KEY_SEMICOLON;
			case 61: return KeyboardKeyCodes::FL_KEY_EQUAL;
			case 65: return KeyboardKeyCodes::FL_KEY_A;
			case 66: return KeyboardKeyCodes::FL_KEY_B;
			case 67: return KeyboardKeyCodes::FL_KEY_C;
			case 68: return KeyboardKeyCodes::FL_KEY_D;
			case 69: return KeyboardKeyCodes::FL_KEY_E;
			case 70: return KeyboardKeyCodes::FL_KEY_F;
			case 71: return KeyboardKeyCodes::FL_KEY_G;
			case 72: return KeyboardKeyCodes::FL_KEY_H;
			case 73: return KeyboardKeyCodes::FL_KEY_I;
			case 74: return KeyboardKeyCodes::FL_KEY_J;
			case 75: return KeyboardKeyCodes::FL_KEY_K;
			case 76: return KeyboardKeyCodes::FL_KEY_L;
			case 77: return KeyboardKeyCodes::FL_KEY_M;
			case 78: return KeyboardKeyCodes::FL_KEY_N;
			case 79: return KeyboardKeyCodes::FL_KEY_O;
			case 80: return KeyboardKeyCodes::FL_KEY_P;
			case 81: return KeyboardKeyCodes::FL_KEY_Q;
			case 82: return KeyboardKeyCodes::FL_KEY_R;
			case 83: return KeyboardKeyCodes::FL_KEY_S;
			case 84: return KeyboardKeyCodes::FL_KEY_T;
			case 85: return KeyboardKeyCodes::FL_KEY_U;
			case 86: return KeyboardKeyCodes::FL_KEY_V;
			case 87: return KeyboardKeyCodes::FL_KEY_W;
			case 88: return KeyboardKeyCodes::FL_KEY_X;
			case 89: return KeyboardKeyCodes::FL_KEY_Y;
			case 90: return KeyboardKeyCodes::FL_KEY_Z;
			case 91: return KeyboardKeyCodes::FL_KEY_LEFT_BRACKET;
			case 92: return KeyboardKeyCodes::FL_KEY_BACKSLASH;
			case 93: return KeyboardKeyCodes::FL_KEY_RIGHT_BRACKET;
			case 96: return KeyboardKeyCodes::FL_KEY_GRAVE_ACCENT;
			case 161: return KeyboardKeyCodes::FL_KEY_WORLD_1;
			case 162: return KeyboardKeyCodes::FL_KEY_WORLD_2;
			case 256: return KeyboardKeyCodes::FL_KEY_ESCAPE;
			case 257: return KeyboardKeyCodes::FL_KEY_ENTER;
			case 258: return KeyboardKeyCodes::FL_KEY_TAB;
			case 259: return KeyboardKeyCodes::FL_KEY_BACKSPACE;
			case 260: return KeyboardKeyCodes::FL_KEY_INSERT;
			case 261: return KeyboardKeyCodes::FL_KEY_DELETE;
			case 262: return KeyboardKeyCodes::FL_KEY_RIGHT;
			case 263: return KeyboardKeyCodes::FL_KEY_LEFT;
			case 264: return KeyboardKeyCodes::FL_KEY_DOWN;
			case 265: return KeyboardKeyCodes::FL_KEY_UP;
			case 266: return KeyboardKeyCodes::FL_KEY_PAGE_UP;
			case 267: return KeyboardKeyCodes::FL_KEY_PAGE_DOWN;
			case 268: return KeyboardKeyCodes::FL_KEY_HOME;
			case 269: return KeyboardKeyCodes::FL_KEY_END;
			case 280: return KeyboardKeyCodes::FL_KEY_CAPS_LOCK;
			case 281: return KeyboardKeyCodes::FL_KEY_SCROLL_LOCK;
			case 282: return KeyboardKeyCodes::FL_KEY_NUM_LOCK;
			case 283: return KeyboardKeyCodes::FL_KEY_PRINT_SCREEN;
			case 284: return KeyboardKeyCodes::FL_KEY_PAUSE;
			case 290: return KeyboardKeyCodes::FL_KEY_F1;
			case 291: return KeyboardKeyCodes::FL_KEY_F2;
			case 292: return KeyboardKeyCodes::FL_KEY_F3;
			case 293: return KeyboardKeyCodes::FL_KEY_F4;
			case 294: return KeyboardKeyCodes::FL_KEY_F5;
			case 295: return KeyboardKeyCodes::FL_KEY_F6;
			case 296: return KeyboardKeyCodes::FL_KEY_F7;
			case 297: return KeyboardKeyCodes::FL_KEY_F8;
			case 298: return KeyboardKeyCodes::FL_KEY_F9;
			case 299: return KeyboardKeyCodes::FL_KEY_F10;
			case 300: return KeyboardKeyCodes::FL_KEY_F11;
			case 301: return KeyboardKeyCodes::FL_KEY_F12;
			case 302: return KeyboardKeyCodes::FL_KEY_F13;
			case 303: return KeyboardKeyCodes::FL_KEY_F14;
			case 304: return KeyboardKeyCodes::FL_KEY_F15;
			case 305: return KeyboardKeyCodes::FL_KEY_F16;
			case 306: return KeyboardKeyCodes::FL_KEY_F17;
			case 307: return KeyboardKeyCodes::FL_KEY_F18;
			case 308: return KeyboardKeyCodes::FL_KEY_F19;
			case 309: return KeyboardKeyCodes::FL_KEY_F20;
			case 310: return KeyboardKeyCodes::FL_KEY_F21;
			case 311: return KeyboardKeyCodes::FL_KEY_F22;
			case 312: return KeyboardKeyCodes::FL_KEY_F23;
			case 313: return KeyboardKeyCodes::FL_KEY_F24;
			case 314: return KeyboardKeyCodes::FL_KEY_F25;
			case 320: return KeyboardKeyCodes::FL_KEY_KP_0;
			case 321: return KeyboardKeyCodes::FL_KEY_KP_1;
			case 322: return KeyboardKeyCodes::FL_KEY_KP_2;
			case 323: return KeyboardKeyCodes::FL_KEY_KP_3;
			case 324: return KeyboardKeyCodes::FL_KEY_KP_4;
			case 325: return KeyboardKeyCodes::FL_KEY_KP_5;
			case 326: return KeyboardKeyCodes::FL_KEY_KP_6;
			case 327: return KeyboardKeyCodes::FL_KEY_KP_7;
			case 328: return KeyboardKeyCodes::FL_KEY_KP_8;
			case 329: return KeyboardKeyCodes::FL_KEY_KP_9;
			case 330: return KeyboardKeyCodes::FL_KEY_KP_DECIMAL;
			case 331: return KeyboardKeyCodes::FL_KEY_KP_DIVIDE;
			case 332: return KeyboardKeyCodes::FL_KEY_KP_MULTIPLY;
			case 333: return KeyboardKeyCodes::FL_KEY_KP_SUBTRACT;
			case 334: return KeyboardKeyCodes::FL_KEY_KP_ADD;
			case 335: return KeyboardKeyCodes::FL_KEY_KP_ENTER;
			case 336: return KeyboardKeyCodes::FL_KEY_KP_EQUAL;
			case 340: return KeyboardKeyCodes::FL_KEY_LEFT_SHIFT;
			case 341: return KeyboardKeyCodes::FL_KEY_LEFT_CONTROL;
			case 342: return KeyboardKeyCodes::FL_KEY_LEFT_ALT;
			case 343: return KeyboardKeyCodes::FL_KEY_LEFT_SUPER;
			case 344: return KeyboardKeyCodes::FL_KEY_RIGHT_SHIFT;
			case 345: return KeyboardKeyCodes::FL_KEY_RIGHT_CONTROL;
			case 346: return KeyboardKeyCodes::FL_KEY_RIGHT_ALT;
			case 347: return KeyboardKeyCodes::FL_KEY_RIGHT_SUPER;
			case 348: return KeyboardKeyCodes::FL_KEY_MENU;
		}
		return KeyboardKeyCodes::FL_KEY_UNKNOWN;
	}

	virtual MouseButtonCodes GetFLMouseButtonCodeImpl(int code) const override
	{
		switch (code)
		{
			case 0: return MouseButtonCodes::FL_MOUSE_BUTTON_1;
			case 1: return MouseButtonCodes::FL_MOUSE_BUTTON_2;
			case 2: return MouseButtonCodes::FL_MOUSE_BUTTON_3;
			case 3: return MouseButtonCodes::FL_MOUSE_BUTTON_4;
			case 4: return MouseButtonCodes::FL_MOUSE_BUTTON_5;
			case 5: return MouseButtonCodes::FL_MOUSE_BUTTON_6;
			case 6: return MouseButtonCodes::FL_MOUSE_BUTTON_7;
			case 7: return MouseButtonCodes::FL_MOUSE_BUTTON_8;
			case 8: return MouseButtonCodes::FL_MOUSE_BUTTON_LAST;
			case 9: return MouseButtonCodes::FL_MOUSE_BUTTON_LEFT;
			case 10: return MouseButtonCodes::FL_MOUSE_BUTTON_RIGHT;
			case 11: return MouseButtonCodes::FL_MOUSE_BUTTON_MIDDLE;
		}
		return MouseButtonCodes::FL_MOUSE_BUTTON_UNKNOWN;
	}
};

std::shared_ptr<Input> Input::_instance = std::make_shared<ExampleTestInput>();

class InputTest
	: public ::testing::Test
{
public:
	void SetUp() override { }

	void TearDown() override { }
};

TEST_F(InputTest, IsKeyPressed)
{
	for (int i = 0; i < 350; ++i) {
		bool expect = false;
		if (Input::GetFLKeyboardKeyCode(i) == KeyboardKeyCodes::FL_KEY_ENTER) expect = true;
		EXPECT_EQ(Input::IsKeyPressed(Input::GetFLKeyboardKeyCode(i)), expect);
	}
}

TEST_F(InputTest, IsMouseButtonPressed)
{
	for (int i = 0; i < 15; ++i) {
		bool expect = false;
		if (Input::GetFLMouseButtonCode(i) == MouseButtonCodes::FL_MOUSE_BUTTON_LEFT) expect = true;
		EXPECT_EQ(Input::IsMouseButtonPressed(Input::GetFLMouseButtonCode(i)), expect);
	}
}

TEST_F(InputTest, GetMousePosition)
{
	EXPECT_EQ(Input::GetMousePosition() == std::make_pair(0.5, 10.35), true);
	EXPECT_EQ(Input::GetMousePosition() == std::make_pair(0.0, 10.35), false);
	EXPECT_EQ(Input::GetMousePosition() == std::make_pair(0.5, 10.0), false);
	EXPECT_EQ(Input::GetMousePosition() == std::make_pair(0.5, 10.3), false);
}

TEST_F(InputTest, GetMouseX)
{
	EXPECT_EQ(Input::GetMouseX() == 0.5, true);
	EXPECT_EQ(Input::GetMouseX() == 0.0, false);
	EXPECT_EQ(Input::GetMouseX() == 0.54, false);
	EXPECT_EQ(Input::GetMouseX() == 0.49, false);
}

TEST_F(InputTest, GetMouseY)
{
	EXPECT_EQ(Input::GetMouseY() == 10.35, true);
	EXPECT_EQ(Input::GetMouseY() == 10.3, false);
	EXPECT_EQ(Input::GetMouseY() == 10.0, false);
	EXPECT_EQ(Input::GetMouseY() == 10.34, false);
}