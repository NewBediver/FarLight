#include <gtest/gtest.h>
#include <FarLight/EventSystem/EventDispatcher.h>

#include <FarLight/EventSystem/KeyboardEvents/KeyboardKeyPressedEvent.h>
#include <FarLight/EventSystem/KeyboardEvents/KeyboardKeyReleasedEvent.h>
#include <FarLight/EventSystem/KeyboardEvents/KeyboardKeyTypedEvent.h>

#include <FarLight/EventSystem/MouseEvents/MouseButtonPressedEvent.h>
#include <FarLight/EventSystem/MouseEvents/MouseButtonReleasedEvent.h>
#include <FarLight/EventSystem/MouseEvents/MouseMovedEvent.h>
#include <FarLight/EventSystem/MouseEvents/MouseScrolledEvent.h>

#include <FarLight/EventSystem/WindowEvents/WindowClosedEvent.h>
#include <FarLight/EventSystem/WindowEvents/WindowResizedEvent.h>

using namespace FarLight;

class EventDispatcherTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		kp = new KeyboardKeyPressedEvent(10, false);
		kr = new KeyboardKeyReleasedEvent(7);
		kt = new KeyboardKeyTypedEvent(4);

		mp = new MouseButtonPressedEvent(10);
		mr = new MouseButtonReleasedEvent(7);
		mm = new MouseMovedEvent(0.124, 0.1249);
		ms = new MouseScrolledEvent(7.5871, 6.42);

		wc = new WindowClosedEvent();
		wr = new WindowResizedEvent(20, 15543);

		dskp = new EventDispatcher(*kp);
		dskr = new EventDispatcher(*kr);
		dskt = new EventDispatcher(*kt);
		dsmp = new EventDispatcher(*mp);
		dsmr = new EventDispatcher(*mr);
		dsmm = new EventDispatcher(*mm);
		dsms = new EventDispatcher(*ms);
		dswc = new EventDispatcher(*wc);
		dswr = new EventDispatcher(*wr);
	}

	void TearDown() override
	{
		delete dskp;
		delete dskr;
		delete dskt;
		delete dsmp;
		delete dsmr;
		delete dsmm;
		delete dsms;
		delete dswc;
		delete dswr;

		delete kp;
		delete kr;
		delete kt;

		delete mp;
		delete mr;
		delete mm;
		delete ms;

		delete wc;
		delete wr;
	}

	bool TestFunction(const Event&) { return true; }

	KeyboardKeyPressedEvent* kp;
	KeyboardKeyReleasedEvent* kr;
	KeyboardKeyTypedEvent* kt;

	MouseButtonPressedEvent* mp;
	MouseButtonReleasedEvent* mr;
	MouseMovedEvent* mm;
	MouseScrolledEvent* ms;

	WindowClosedEvent* wc;
	WindowResizedEvent* wr;

	EventDispatcher* dskp;
	EventDispatcher* dskr;
	EventDispatcher* dskt;
	EventDispatcher* dsmp;
	EventDispatcher* dsmr;
	EventDispatcher* dsmm;
	EventDispatcher* dsms;
	EventDispatcher* dswc;
	EventDispatcher* dswr;
};

TEST_F(EventDispatcherTest, KeyboardKeyPressedEvent)
{
	EXPECT_EQ(dskp->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
	EXPECT_EQ(dskp->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskp->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskp->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskp->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskp->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskp->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskp->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskp->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
}

TEST_F(EventDispatcherTest, KeyboardKeyReleasedEvent)
{
	EXPECT_EQ(dskr->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskr->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
	EXPECT_EQ(dskr->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskr->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskr->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskr->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskr->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskr->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskr->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
}

TEST_F(EventDispatcherTest, KeyboardKeyTypedEvent)
{
	EXPECT_EQ(dskt->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskt->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskt->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
	EXPECT_EQ(dskt->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskt->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskt->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskt->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskt->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dskt->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
}

TEST_F(EventDispatcherTest, MouseButtonPressedEvent)
{
	EXPECT_EQ(dsmp->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmp->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmp->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmp->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
	EXPECT_EQ(dsmp->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmp->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmp->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmp->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmp->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
}

TEST_F(EventDispatcherTest, MouseButtonReleasedEvent)
{
	EXPECT_EQ(dsmr->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmr->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmr->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmr->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmr->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
	EXPECT_EQ(dsmr->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmr->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmr->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmr->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
}

TEST_F(EventDispatcherTest, MouseMovedEvent)
{
	EXPECT_EQ(dsmm->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmm->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmm->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmm->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmm->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmm->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
	EXPECT_EQ(dsmm->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmm->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsmm->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
}

TEST_F(EventDispatcherTest, MouseScrolledEvent)
{
	EXPECT_EQ(dsms->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsms->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsms->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsms->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsms->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsms->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsms->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
	EXPECT_EQ(dsms->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dsms->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
}

TEST_F(EventDispatcherTest, WindowClosedEvent)
{
	EXPECT_EQ(dswc->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswc->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswc->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswc->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswc->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswc->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswc->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswc->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
	EXPECT_EQ(dswc->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
}

TEST_F(EventDispatcherTest, WindowResizedEvent)
{
	EXPECT_EQ(dswr->Dispatch<KeyboardKeyPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswr->Dispatch<KeyboardKeyReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswr->Dispatch<KeyboardKeyTypedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswr->Dispatch<MouseButtonPressedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswr->Dispatch<MouseButtonReleasedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswr->Dispatch<MouseMovedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswr->Dispatch<MouseScrolledEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswr->Dispatch<WindowClosedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), false);
	EXPECT_EQ(dswr->Dispatch<WindowResizedEvent>(std::bind(&EventDispatcherTest::TestFunction, this, std::placeholders::_1)), true);
}