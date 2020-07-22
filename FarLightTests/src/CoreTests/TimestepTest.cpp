#include <gtest/gtest.h>
#include <FarLight/Core/Timestep.h>

using namespace FarLight;

class TimestepTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		t1 = new Timestep();
		t2 = new Timestep(0.5f);
		t3 = new Timestep(2.78f);
	}

	void TearDown() override
	{
		delete t1;
		delete t2;
		delete t3;
	}

	Timestep* t1;
	Timestep* t2;
	Timestep* t3;
};

TEST_F(TimestepTest, operatorFloat)
{
	for (float temp = 0.0f; temp < 10.0f; temp += 0.001f)
	{
		EXPECT_EQ(temp + static_cast<float>(*t1), temp + 0.0f);
		EXPECT_EQ(temp + static_cast<float>(*t2), temp + 0.5f);
		EXPECT_EQ(temp + static_cast<float>(*t3), temp + 2.78f);
	}
}

TEST_F(TimestepTest, GetSeconds)
{
	for (float temp = 0.0f; temp < 10.0f; temp += 0.001f)
	{
		EXPECT_EQ(temp + t1->GetSeconds(), temp + 0.0f);
		EXPECT_EQ(temp + t2->GetSeconds(), temp + 0.5f);
		EXPECT_EQ(temp + t3->GetSeconds(), temp + 2.78f);
	}
}

TEST_F(TimestepTest, GetMilliseconds)
{
	for (float temp = 0.0f; temp < 10.0f; temp += 0.001f)
	{
		EXPECT_EQ(temp + t1->GetMilliseconds(), temp + 0.0f);
		EXPECT_EQ(temp + t2->GetMilliseconds(), temp + 500.0f);
		EXPECT_EQ(temp + t3->GetMilliseconds(), temp + 2780.0f);
	}
}