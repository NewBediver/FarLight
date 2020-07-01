#include <gtest/gtest.h>
#include <FarLight/EventSystem/WindowEvents/WindowResizedEvent.h>

using namespace FarLight;

class WindowResizedEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new WindowResizedEvent(10, 0);
		e2 = new WindowResizedEvent(20, 15543);
		e3 = new WindowResizedEvent(745343, 2434536);
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}

	WindowResizedEvent* e1;
	WindowResizedEvent* e2;
	WindowResizedEvent* e3;
};

TEST_F(WindowResizedEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "WindowResized");
	EXPECT_EQ(e2->GetName(), "WindowResized");
	EXPECT_EQ(e3->GetName(), "WindowResized");
}

TEST_F(WindowResizedEventTest, GetStaticType)
{
	EXPECT_EQ(WindowResizedEvent::GetStaticType(), EventType::WindowResizedEventType);
}

TEST_F(WindowResizedEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::WindowResizedEventType);
	EXPECT_EQ(e2->GetType(), EventType::WindowResizedEventType);
	EXPECT_EQ(e3->GetType(), EventType::WindowResizedEventType);
}

TEST_F(WindowResizedEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "WindowResized: (10, 0).");
	EXPECT_EQ(e2->ToString(), "WindowResized: (20, 15543).");
	EXPECT_EQ(e3->ToString(), "WindowResized: (745343, 2434536).");
}

TEST_F(WindowResizedEventTest, GetWidth)
{
	EXPECT_EQ(e1->GetWidth(), 10);
	EXPECT_EQ(e2->GetWidth(), 20);
	EXPECT_EQ(e3->GetWidth(), 745343);
}

TEST_F(WindowResizedEventTest, GetHeight)
{
	EXPECT_EQ(e1->GetHeight(), 0);
	EXPECT_EQ(e2->GetHeight(), 15543);
	EXPECT_EQ(e3->GetHeight(), 2434536);
}

TEST_F(WindowResizedEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::ApplicationEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 1);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::ApplicationEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 1);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::ApplicationEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 1);
}

TEST_F(WindowResizedEventTest, IsInCategory)
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

TEST_F(WindowResizedEventTest, Handle)
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