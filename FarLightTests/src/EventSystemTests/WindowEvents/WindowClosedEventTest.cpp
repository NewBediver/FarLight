#include <gtest/gtest.h>
#include <FarLight/EventSystem/WindowEvents/WindowClosedEvent.h>

using namespace FarLight;

class WindowClosedEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new WindowClosedEvent();
		e2 = new WindowClosedEvent();
		e3 = new WindowClosedEvent();
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}

	WindowClosedEvent* e1;
	WindowClosedEvent* e2;
	WindowClosedEvent* e3;
};

TEST_F(WindowClosedEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "WindowClosed");
	EXPECT_EQ(e2->GetName(), "WindowClosed");
	EXPECT_EQ(e3->GetName(), "WindowClosed");
}

TEST_F(WindowClosedEventTest, GetStaticType)
{
	EXPECT_EQ(WindowClosedEvent::GetStaticType(), EventType::WindowClosedEventType);
}

TEST_F(WindowClosedEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::WindowClosedEventType);
	EXPECT_EQ(e2->GetType(), EventType::WindowClosedEventType);
	EXPECT_EQ(e3->GetType(), EventType::WindowClosedEventType);
}

TEST_F(WindowClosedEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "WindowClosed");
	EXPECT_EQ(e1->ToString(), e1->GetName());
	EXPECT_EQ(e2->ToString(), "WindowClosed");
	EXPECT_EQ(e2->ToString(), e2->GetName());
	EXPECT_EQ(e3->ToString(), "WindowClosed");
	EXPECT_EQ(e3->ToString(), e3->GetName());
}

TEST_F(WindowClosedEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::ApplicationEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 1);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::ApplicationEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 1);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::ApplicationEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 1);
}

TEST_F(WindowClosedEventTest, IsInCategory)
{
	EXPECT_EQ(e1->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::ApplicationEventCategory), true);
	EXPECT_EQ(e1->IsInCategory(EventCategory::InputEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::MouseEventCategory), false);
	EXPECT_EQ(e1->IsInCategory(EventCategory::MouseButtonEventCategory), false);

	EXPECT_EQ(e2->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::ApplicationEventCategory), true);
	EXPECT_EQ(e2->IsInCategory(EventCategory::InputEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::MouseEventCategory), false);
	EXPECT_EQ(e2->IsInCategory(EventCategory::MouseButtonEventCategory), false);

	EXPECT_EQ(e3->IsInCategory(EventCategory::None), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::ApplicationEventCategory), true);
	EXPECT_EQ(e3->IsInCategory(EventCategory::InputEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::KeyboardEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::MouseEventCategory), false);
	EXPECT_EQ(e3->IsInCategory(EventCategory::MouseButtonEventCategory), false);
}