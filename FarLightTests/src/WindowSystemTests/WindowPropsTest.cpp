#include <gtest/gtest.h>
#include <FarLight/WindowSystem/WindowProps.h>

using namespace FarLight;

class WindowPropsTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		p1 = new WindowProps();
		p2 = new WindowProps("Testing1");
		p3 = new WindowProps("Testing2", 15);
		p4 = new WindowProps("Testing3", 23, 46);
	}

	void TearDown() override
	{
		delete p1;
		delete p2;
		delete p3;
		delete p4;
	}

	WindowProps* p1;
	WindowProps* p2;
	WindowProps* p3;
	WindowProps* p4;
};

TEST_F(WindowPropsTest, Constructor)
{
	EXPECT_EQ(p1->_title, "FarLight Engine");
	EXPECT_EQ(p1->_width, 1280);
	EXPECT_EQ(p1->_height, 720);

	EXPECT_EQ(p2->_title, "Testing1");
	EXPECT_EQ(p2->_width, 1280);
	EXPECT_EQ(p2->_height, 720);

	EXPECT_EQ(p3->_title, "Testing2");
	EXPECT_EQ(p3->_width, 15);
	EXPECT_EQ(p3->_height, 720);

	EXPECT_EQ(p4->_title, "Testing3");
	EXPECT_EQ(p4->_width, 23);
	EXPECT_EQ(p4->_height, 46);
}