#include <gtest/gtest.h>
#include <FarLight/EventSystem/MouseEvents/MouseButtonReleasedEvent.h>

using namespace FarLight;

class MouseButtonReleasedEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new MouseButtonReleasedEvent(10);
		e2 = new MouseButtonReleasedEvent(0);
		e3 = new MouseButtonReleasedEvent(7);
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}

	MouseButtonReleasedEvent* e1;
	MouseButtonReleasedEvent* e2;
	MouseButtonReleasedEvent* e3;
};

TEST_F(MouseButtonReleasedEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "MouseButtonReleased");
	EXPECT_EQ(e2->GetName(), "MouseButtonReleased");
	EXPECT_EQ(e3->GetName(), "MouseButtonReleased");
}

TEST_F(MouseButtonReleasedEventTest, GetStaticType)
{
	EXPECT_EQ(MouseButtonReleasedEvent::GetStaticType(), EventType::MouseButtonReleasedEventType);
}

TEST_F(MouseButtonReleasedEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::MouseButtonReleasedEventType);
	EXPECT_EQ(e2->GetType(), EventType::MouseButtonReleasedEventType);
	EXPECT_EQ(e3->GetType(), EventType::MouseButtonReleasedEventType);
}

TEST_F(MouseButtonReleasedEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "MouseButtonReleased: (10).");
	EXPECT_EQ(e2->ToString(), "MouseButtonReleased: (0).");
	EXPECT_EQ(e3->ToString(), "MouseButtonReleased: (7).");
}

TEST_F(MouseButtonReleasedEventTest, GetButton)
{
	EXPECT_EQ(e1->GetButton(), 10);
	EXPECT_EQ(e2->GetButton(), 0);
	EXPECT_EQ(e3->GetButton(), 7);
}

TEST_F(MouseButtonReleasedEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory | EventCategory::MouseButtonEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 26);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory | EventCategory::MouseButtonEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 26);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::MouseEventCategory | EventCategory::MouseButtonEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 26);
}

TEST_F(MouseButtonReleasedEventTest, IsInCategory)
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