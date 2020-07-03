#include <gtest/gtest.h>
#include <FarLight/EventSystem/KeyboardEvents/KeyboardKeyTypedEvent.h>

using namespace FarLight;

class KeyboardKeyTypedEventTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		e1 = new KeyboardKeyTypedEvent(10);
		e2 = new KeyboardKeyTypedEvent(0);
		e3 = new KeyboardKeyTypedEvent(7);
	}

	void TearDown() override
	{
		delete e1;
		delete e2;
		delete e3;
	}

	KeyboardKeyTypedEvent* e1;
	KeyboardKeyTypedEvent* e2;
	KeyboardKeyTypedEvent* e3;
};

TEST_F(KeyboardKeyTypedEventTest, GetName)
{
	EXPECT_EQ(e1->GetName(), "KeyboardKeyTyped");
	EXPECT_EQ(e2->GetName(), "KeyboardKeyTyped");
	EXPECT_EQ(e3->GetName(), "KeyboardKeyTyped");
}

TEST_F(KeyboardKeyTypedEventTest, GetStaticType)
{
	EXPECT_EQ(KeyboardKeyTypedEvent::GetStaticType(), EventType::KeyboardKeyTypedEventType);
}

TEST_F(KeyboardKeyTypedEventTest, GetType)
{
	EXPECT_EQ(e1->GetType(), EventType::KeyboardKeyTypedEventType);
	EXPECT_EQ(e2->GetType(), EventType::KeyboardKeyTypedEventType);
	EXPECT_EQ(e3->GetType(), EventType::KeyboardKeyTypedEventType);
}

TEST_F(KeyboardKeyTypedEventTest, ToString)
{
	EXPECT_EQ(e1->ToString(), "KeyboardKeyTypedEvent: (10).");
	EXPECT_EQ(e2->ToString(), "KeyboardKeyTypedEvent: (0).");
	EXPECT_EQ(e3->ToString(), "KeyboardKeyTypedEvent: (7).");
}

TEST_F(KeyboardKeyTypedEventTest, GetKeyCode)
{
	EXPECT_EQ(e1->GetKeyCode(), 10);
	EXPECT_EQ(e2->GetKeyCode(), 0);
	EXPECT_EQ(e3->GetKeyCode(), 7);
}

TEST_F(KeyboardKeyTypedEventTest, GetCategoryFlags)
{
	EXPECT_EQ(e1->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e1->GetCategoryFlags(), 6);
	EXPECT_EQ(e2->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e2->GetCategoryFlags(), 6);
	EXPECT_EQ(e3->GetCategoryFlags(), EventCategory::InputEventCategory | EventCategory::KeyboardEventCategory);
	EXPECT_EQ(e3->GetCategoryFlags(), 6);
}

TEST_F(KeyboardKeyTypedEventTest, IsInCategory)
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

TEST_F(KeyboardKeyTypedEventTest, Handle)
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