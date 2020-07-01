#include <gtest/gtest.h>
#include <FarLight/EventSystem/KeyboardEvents/KeyboardKeyReleasedEvent.h>

using namespace FarLight;

class KeyboardKeyReleasedEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new KeyboardKeyReleasedEvent(10);
		e2 = new KeyboardKeyReleasedEvent(0);
		e3 = new KeyboardKeyReleasedEvent(7);
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}

	KeyboardKeyReleasedEvent* e1;
	KeyboardKeyReleasedEvent* e2;
	KeyboardKeyReleasedEvent* e3;
};

TEST_F(KeyboardKeyReleasedEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "KeyboardKeyReleased");
	EXPECT_EQ(e2->GetName(), "KeyboardKeyReleased");
	EXPECT_EQ(e3->GetName(), "KeyboardKeyReleased");
}

TEST_F(KeyboardKeyReleasedEventTest, GetStaticType)
{
	EXPECT_EQ(KeyboardKeyReleasedEvent::GetStaticType(), EventType::KeyboardKeyReleasedEventType);
}

TEST_F(KeyboardKeyReleasedEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::KeyboardKeyReleasedEventType);
	EXPECT_EQ(e2->GetType(), EventType::KeyboardKeyReleasedEventType);
	EXPECT_EQ(e3->GetType(), EventType::KeyboardKeyReleasedEventType);
}

TEST_F(KeyboardKeyReleasedEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "KeyboardKeyReleasedEvent: (10).");
	EXPECT_EQ(e2->ToString(), "KeyboardKeyReleasedEvent: (0).");
	EXPECT_EQ(e3->ToString(), "KeyboardKeyReleasedEvent: (7).");
}

TEST_F(KeyboardKeyReleasedEventTest, GetKeyCode)
{
	EXPECT_EQ(e1->GetKeyCode(), 10);
	EXPECT_EQ(e2->GetKeyCode(), 0);
	EXPECT_EQ(e3->GetKeyCode(), 7);
}

TEST_F(KeyboardKeyReleasedEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 6);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 6);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 6);
}

TEST_F(KeyboardKeyReleasedEventTest, IsInCategory)
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

TEST_F(KeyboardKeyReleasedEventTest, Handle)
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