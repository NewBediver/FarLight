#include <gtest/gtest.h>
#include <FarLight/EventSystem/KeyboardEvents/KeyboardKeyPressedEvent.h>

using namespace FarLight;

class KeyboardKeyPressedEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new KeyboardKeyPressedEvent(10, false);
		e2 = new KeyboardKeyPressedEvent(0, false);
		e3 = new KeyboardKeyPressedEvent(7, true);
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}
	
	KeyboardKeyPressedEvent* e1;
	KeyboardKeyPressedEvent* e2;
	KeyboardKeyPressedEvent* e3;
};

TEST_F(KeyboardKeyPressedEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "KeyboardKeyPressed");
	EXPECT_EQ(e2->GetName(), "KeyboardKeyPressed");
	EXPECT_EQ(e3->GetName(), "KeyboardKeyPressed");
}

TEST_F(KeyboardKeyPressedEventTest, GetStaticType)
{
	EXPECT_EQ(KeyboardKeyPressedEvent::GetStaticType(), EventType::KeyboardKeyPressedEventType);
}

TEST_F(KeyboardKeyPressedEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::KeyboardKeyPressedEventType);
	EXPECT_EQ(e2->GetType(), EventType::KeyboardKeyPressedEventType);
	EXPECT_EQ(e3->GetType(), EventType::KeyboardKeyPressedEventType);
}

TEST_F(KeyboardKeyPressedEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "KeyboardKeyPressedEvent: (10). Is repeated: false.");
	EXPECT_EQ(e2->ToString(), "KeyboardKeyPressedEvent: (0). Is repeated: false.");
	EXPECT_EQ(e3->ToString(), "KeyboardKeyPressedEvent: (7). Is repeated: true.");
}

TEST_F(KeyboardKeyPressedEventTest, GetKeyCode)
{
	EXPECT_EQ(e1->GetKeyCode(), 10);
	EXPECT_EQ(e2->GetKeyCode(), 0);
	EXPECT_EQ(e3->GetKeyCode(), 7);
}

TEST_F(KeyboardKeyPressedEventTest, IsRepeated)
{
	EXPECT_EQ(e1->IsRepeated(), false);
	EXPECT_EQ(e2->IsRepeated(), false);
	EXPECT_EQ(e3->IsRepeated(), true);
}

TEST_F(KeyboardKeyPressedEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 6);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 6);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 6);
}

TEST_F(KeyboardKeyPressedEventTest, IsInCategory)
{
	EXPECT_EQ(e1->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e1->IsInCategory(EventCategory::KeyboardEventCategory), true);
	EXPECT_EQ(e1->IsInCategory(EventCategory::MouseEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::MouseButtonEventCategory), false);

	EXPECT_EQ(e2->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e2->IsInCategory(EventCategory::KeyboardEventCategory), true);
	EXPECT_EQ(e2->IsInCategory(EventCategory::MouseEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::MouseButtonEventCategory), false);

	EXPECT_EQ(e3->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e3->IsInCategory(EventCategory::KeyboardEventCategory), true);
	EXPECT_EQ(e3->IsInCategory(EventCategory::MouseEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::MouseButtonEventCategory), false);
}

TEST_F(KeyboardKeyPressedEventTest, Handle)
{
	EXPECT_EQ(e1->IsHandled(), false);
	e1->SetHandled(true);
	EXPECT_EQ(e1->IsHandled(), true);
	e1->SetHandled(false);
	EXPECT_EQ(e1->IsHandled(), false);
	e1->SetHandled(true);
	EXPECT_EQ(e1->IsHandled(), true);
	
	EXPECT_EQ(e2->IsHandled(), false);
	e2->SetHandled(true);
	EXPECT_EQ(e2->IsHandled(), true);
	e2->SetHandled(false);
	EXPECT_EQ(e2->IsHandled(), false);
	e2->SetHandled(true);
	EXPECT_EQ(e2->IsHandled(), true);

	EXPECT_EQ(e3->IsHandled(), false);
	e3->SetHandled(true);
	EXPECT_EQ(e3->IsHandled(), true);
	e3->SetHandled(false);
	EXPECT_EQ(e3->IsHandled(), false);
	e3->SetHandled(true);
	EXPECT_EQ(e3->IsHandled(), true);
}