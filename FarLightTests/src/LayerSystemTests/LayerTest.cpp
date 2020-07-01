#include <gtest/gtest.h>
#include <FarLight/LayerSystem/Layer.h>

using namespace FarLight;

class TestLayerClass
	: public Layer
{
public:
	TestLayerClass()
		: Layer() { }

	TestLayerClass(std::string name)
		: Layer(name) { }

	virtual void OnAttach() override { }
	virtual void OnDetach() override { }
	virtual void OnUpdate() override { }
	virtual void OnEvent(Event& event) override { }
};

class LayerTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		l1 = new TestLayerClass();
		l2 = new TestLayerClass("Test");
	}

	void TearDown() override
	{
		delete l1;
		delete l2;
	}

	Layer* l1;
	Layer* l2;
};

TEST_F(LayerTest, GetName)
{
	EXPECT_EQ(l1->GetName(), "Layer");
	EXPECT_EQ(l2->GetName(), "Test");
}