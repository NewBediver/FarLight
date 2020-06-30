#include <gtest/gtest.h>
#include <FarLight/EventSystem/MouseEvents/MouseScrolledEvent.h>

using namespace FarLight;

class MouseScrolledEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new MouseScrolledEvent(10, 4.6);
		e2 = new MouseScrolledEvent(0.124, 0.1249);
		e3 = new MouseScrolledEvent(7.5871, 6.42);
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}

	MouseScrolledEvent* e1;
	MouseScrolledEvent* e2;
	MouseScrolledEvent* e3;
};

TEST_F(MouseScrolledEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "MouseScrolled");
	EXPECT_EQ(e2->GetName(), "MouseScrolled");
	EXPECT_EQ(e3->GetName(), "MouseScrolled");
}

TEST_F(MouseScrolledEventTest, GetStaticType)
{
	EXPECT_EQ(MouseScrolledEvent::GetStaticType(), EventType::MouseScrolledEventType);
}

TEST_F(MouseScrolledEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::MouseScrolledEventType);
	EXPECT_EQ(e2->GetType(), EventType::MouseScrolledEventType);
	EXPECT_EQ(e3->GetType(), EventType::MouseScrolledEventType);
}

TEST_F(MouseScrolledEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "MouseScrolled: (10.000, 4.600).");
	EXPECT_EQ(e2->ToString(), "MouseScrolled: (0.124, 0.125).");
	EXPECT_EQ(e3->ToString(), "MouseScrolled: (7.587, 6.420).");
}

TEST_F(MouseScrolledEventTest, GetOffsetX)
{
	EXPECT_EQ(e1->GetXOffset(), 10.000);
	EXPECT_EQ(e2->GetXOffset(), 0.124);
	EXPECT_EQ(e3->GetXOffset(), 7.5871);
}

TEST_F(MouseScrolledEventTest, GetOffsetY)
{
	EXPECT_EQ(e1->GetYOffset(), 4.6);
	EXPECT_EQ(e2->GetYOffset(), 0.1249);
	EXPECT_EQ(e3->GetYOffset(), 6.42);
}

TEST_F(MouseScrolledEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 10);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 10);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 10);
}

TEST_F(MouseScrolledEventTest, IsInCategory)
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