#include <gtest/gtest.h>
#include <FarLight/LayerSystem/Layer.h>
#include <FarLight/LayerSystem/LayerStack.h>

#include <algorithm>

using namespace FarLight;

class TestLayerClass
	: public Layer
{
public:
	TestLayerClass()
		: Layer() { }

	TestLayerClass(std::string name)
		: Layer(name) { }

	virtual ~TestLayerClass() = default;

	virtual void OnAttach() override { }
	virtual void OnDetach() override { }
	virtual void OnUpdate() override { }
	virtual void OnEvent(Event& event) override { }
};

class LayerStackTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		ls1 = new LayerStack();
		l1 = new TestLayerClass("Test1");
		l2 = new TestLayerClass("Test2");
		l3 = new TestLayerClass("Test3");
		l4 = new TestLayerClass("Test4");
		l5 = new TestLayerClass("Test5");
	}

	void TearDown() override
	{
		ls1->PopOverlay(l1);
		ls1->PopOverlay(l2);
		ls1->PopOverlay(l3);
		ls1->PopOverlay(l4);
		ls1->PopOverlay(l5);
		delete ls1;
		delete l1;
		delete l2;
		delete l3;
		delete l4;
		delete l5;
	}

	LayerStack* ls1;
	Layer* l1;
	Layer* l2;
	Layer* l3;
	Layer* l4;
	Layer* l5;
};

TEST_F(LayerStackTest, PushLayers)
{
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushLayer(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test1");
	ls1->PushLayer(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test3");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 4);
	EXPECT_EQ((*(ls1->begin() + 3))->GetName(), "Test4");
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 5);
	EXPECT_EQ((*(ls1->begin() + 4))->GetName(), "Test5");
}

TEST_F(LayerStackTest, PushOverlays)
{
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushOverlay(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	ls1->PushOverlay(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test4");
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test1");
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 4);
	EXPECT_EQ((*(ls1->begin() + 3))->GetName(), "Test2");
	ls1->PushOverlay(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 5);
	EXPECT_EQ((*(ls1->begin() + 4))->GetName(), "Test5");
}

TEST_F(LayerStackTest, PushLayerAndPushOverlay)
{
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test1");
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test1");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test1");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test2");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 4);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test1");
	EXPECT_EQ((*(ls1->begin() + 3))->GetName(), "Test2");
	ls1->PushOverlay(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 5);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test1");
	EXPECT_EQ((*(ls1->begin() + 3))->GetName(), "Test2");
	EXPECT_EQ((*(ls1->begin() + 4))->GetName(), "Test5");
}

TEST_F(LayerStackTest, PopLayer)
{
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test1");
	ls1->PopLayer(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	ls1->PopLayer(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test2");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	ls1->PopLayer(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test5");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test2");
	ls1->PopLayer(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PopLayer(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin()+1))->GetName(), "Test4");
	ls1->PopLayer(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
}

TEST_F(LayerStackTest, PopOverlay)
{
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test1");
	ls1->PopOverlay(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	ls1->PopOverlay(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test2");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	ls1->PopOverlay(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test5");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test2");
	ls1->PopOverlay(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PopOverlay(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test3");
	ls1->PopOverlay(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
}

TEST_F(LayerStackTest, PopLayerAndPopOverlay)
{
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test1");
	ls1->PopOverlay(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	ls1->PopOverlay(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test2");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	ls1->PopLayer(l1);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 3);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test5");
	EXPECT_EQ((*(ls1->begin() + 2))->GetName(), "Test2");
	ls1->PopOverlay(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test2");
	ls1->PopLayer(l2);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test3");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test4");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test4");
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 2);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test5");
	EXPECT_EQ((*(ls1->begin() + 1))->GetName(), "Test4");
	ls1->PopOverlay(l4);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 1);
	EXPECT_EQ((*(ls1->begin()))->GetName(), "Test5");
	ls1->PopOverlay(l5);
	EXPECT_EQ(std::distance(ls1->begin(), ls1->end()), 0);
}