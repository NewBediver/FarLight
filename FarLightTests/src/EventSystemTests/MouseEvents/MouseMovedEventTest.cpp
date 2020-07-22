#include <gtest/gtest.h>
#include <FarLight/EventSystem/MouseEvents/MouseMovedEvent.h>

using namespace FarLight;

class MouseMovedEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new MouseMovedEvent(10, 4.6);
		e2 = new MouseMovedEvent(0.124, 0.1249);
		e3 = new MouseMovedEvent(7.5871, 6.42);
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}

	MouseMovedEvent* e1;
	MouseMovedEvent* e2;
	MouseMovedEvent* e3;
};

TEST_F(MouseMovedEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "MouseMoved");
	EXPECT_EQ(e2->GetName(), "MouseMoved");
	EXPECT_EQ(e3->GetName(), "MouseMoved");
}

TEST_F(MouseMovedEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::MouseMovedEventType);
	EXPECT_EQ(e2->GetType(), EventType::MouseMovedEventType);
	EXPECT_EQ(e3->GetType(), EventType::MouseMovedEventType);
}

TEST_F(MouseMovedEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "MouseMoved: (10.000, 4.600).");
	EXPECT_EQ(e2->ToString(), "MouseMoved: (0.124, 0.125).");
	EXPECT_EQ(e3->ToString(), "MouseMoved: (7.587, 6.420).");
}

TEST_F(MouseMovedEventTest, GetX)
{
	EXPECT_EQ(e1->GetX(), 10.000);
	EXPECT_EQ(e2->GetX(), 0.124);
	EXPECT_EQ(e3->GetX(), 7.5871);
}

TEST_F(MouseMovedEventTest, GetY)
{
	EXPECT_EQ(e1->GetY(), 4.6);
	EXPECT_EQ(e2->GetY(), 0.1249);
	EXPECT_EQ(e3->GetY(), 6.42);
}

TEST_F(MouseMovedEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 10);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 10);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 10);
}

TEST_F(MouseMovedEventTest, IsInCategory)
{
	EXPECT_EQ(e1->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e1->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::MouseEventCategory), true);
	EXPECT_EQ(e1->IsInCategory(EventCategory::MouseButtonEventCategory), false);

	EXPECT_EQ(e2->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e2->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::MouseEventCategory), true);
	EXPECT_EQ(e2->IsInCategory(EventCategory::MouseButtonEventCategory), false);

	EXPECT_EQ(e3->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::ApplicationEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::InputEventCategory), true);
	EXPECT_EQ(e3->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::MouseEventCategory), true);
	EXPECT_EQ(e3->IsInCategory(EventCategory::MouseButtonEventCategory), false);
}

TEST_F(MouseMovedEventTest, Handle)
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