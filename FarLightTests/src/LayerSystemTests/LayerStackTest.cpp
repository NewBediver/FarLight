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

	virtual void OnAttach() const override { }
	virtual void OnDetach() const override { }
	virtual void OnUpdate(const Timestep& timestamp) override { }
	virtual void OnEvent(Event& event) override { }
	virtual void OnUserInterfaceRender() override { }
};

class LayerStackTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		ls1 = new LayerStack();
		l1 = std::make_shared<TestLayerClass>("Test1");
		l2 = std::make_shared<TestLayerClass>("Test2");
		l3 = std::make_shared<TestLayerClass>("Test3");
		l4 = std::make_shared<TestLayerClass>("Test4");
		l5 = std::make_shared<TestLayerClass>("Test5");
	}

	void TearDown() override
	{
		delete ls1;
	}

	LayerStack* ls1;
	std::shared_ptr<Layer> l1;
	std::shared_ptr<Layer> l2;
	std::shared_ptr<Layer> l3;
	std::shared_ptr<Layer> l4;
	std::shared_ptr<Layer> l5;
};

TEST_F(LayerStackTest, PushLayers)
{
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
	ls1->PushLayer(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	auto iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	ls1->PushLayer(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	std::advance(iter, 2);
	EXPECT_EQ((*iter)->GetName(), "Test3");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	std::advance(iter, 3);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	ls1->PushLayer(l5);
	iter = ls1->cbegin();
	std::advance(iter, 4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 5);
	EXPECT_EQ((*iter)->GetName(), "Test5");
}

TEST_F(LayerStackTest, PushOverlays)
{
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
	ls1->PushOverlay(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	auto iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	ls1->PushOverlay(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	std::advance(iter, 2);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	std::advance(iter, 3);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushOverlay(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 5);
	iter = ls1->cbegin();
	std::advance(iter, 4);
	EXPECT_EQ((*iter)->GetName(), "Test5");
}

TEST_F(LayerStackTest, PushLayerAndPushOverlay)
{
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	auto iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushOverlay(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 5);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
}

TEST_F(LayerStackTest, PopLayer)
{
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	auto iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	ls1->PopLayer(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	ls1->PopLayer(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	ls1->PopLayer(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopLayer(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopLayer(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopLayer(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	ls1->PopOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
}

TEST_F(LayerStackTest, PopOverlay)
{
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	auto iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	ls1->PopOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	ls1->PopOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	ls1->PopOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopOverlay(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	ls1->PopOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	ls1->PushOverlay(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test3");
	ls1->PushOverlay(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 5);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 4);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	ls1->PopOverlay(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	ls1->PopLayer(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	ls1->PopLayer(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
}

TEST_F(LayerStackTest, PopLayerAndPopOverlay)
{
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
	ls1->PushOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	auto iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test1");
	ls1->PopOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	ls1->PopOverlay(l1);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
	ls1->PushOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PushLayer(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test3");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopLayer(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test2");
	ls1->PopOverlay(l2);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	ls1->PushOverlay(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test3");
	ls1->PopLayer(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	ls1->PushLayer(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 3);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test4");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test5");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test3");
	ls1->PopLayer(l4);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 2);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test5");
	std::advance(iter, 1);
	EXPECT_EQ((*iter)->GetName(), "Test3");
	ls1->PopOverlay(l3);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 1);
	iter = ls1->cbegin();
	EXPECT_EQ((*iter)->GetName(), "Test5");
	ls1->PopLayer(l5);
	EXPECT_EQ(std::distance(ls1->cbegin(), ls1->cend()), 0);
}