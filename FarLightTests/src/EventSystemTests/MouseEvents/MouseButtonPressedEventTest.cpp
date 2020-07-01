#include <gtest/gtest.h>
#include <FarLight/EventSystem/MouseEvents/MouseButtonPressedEvent.h>

using namespace FarLight;

class MouseButtonPressedEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new MouseButtonPressedEvent(10);
		e2 = new MouseButtonPressedEvent(0);
		e3 = new MouseButtonPressedEvent(7);
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}

	MouseButtonPressedEvent* e1;
	MouseButtonPressedEvent* e2;
	MouseButtonPressedEvent* e3;
};

TEST_F(MouseButtonPressedEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "MouseButtonPressed");
	EXPECT_EQ(e2->GetName(), "MouseButtonPressed");
	EXPECT_EQ(e3->GetName(), "MouseButtonPressed");
}

TEST_F(MouseButtonPressedEventTest, GetStaticType)
{
	EXPECT_EQ(MouseButtonPressedEvent::GetStaticType(), EventType::MouseButtonPressedEventType);
}

TEST_F(MouseButtonPressedEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::MouseButtonPressedEventType);
	EXPECT_EQ(e2->GetType(), EventType::MouseButtonPressedEventType);
	EXPECT_EQ(e3->GetType(), EventType::MouseButtonPressedEventType);
}

TEST_F(MouseButtonPressedEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "MouseButtonPressed: (10).");
	EXPECT_EQ(e2->ToString(), "MouseButtonPressed: (0).");
	EXPECT_EQ(e3->ToString(), "MouseButtonPressed: (7).");
}

TEST_F(MouseButtonPressedEventTest, GetButton)
{
	EXPECT_EQ(e1->GetButton(), 10);
	EXPECT_EQ(e2->GetButton(), 0);
	EXPECT_EQ(e3->GetButton(), 7);
}

TEST_F(MouseButtonPressedEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory | EventCategory::MouseButtonEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 26);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory | EventCategory::MouseButtonEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 26);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory | EventCategory::MouseButtonEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 26);
}

TEST_F(MouseButtonPressedEventTest, IsInCategory)
{
	EXPECT_EQ(e1->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e1->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::MouseEventCategory), true);
	EXPECT_EQ(e1->IsInCategory(EventCategory::MouseButtonEventCategory), true);

	EXPECT_EQ(e2->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e2->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::MouseEventCategory), true);
	EXPECT_EQ(e2->IsInCategory(EventCategory::MouseButtonEventCategory), true);

	EXPECT_EQ(e3->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e3->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::MouseEventCategory), true);
	EXPECT_EQ(e3->IsInCategory(EventCategory::MouseButtonEventCategory), true);
}

TEST_F(MouseButtonPressedEventTest, Handle)
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