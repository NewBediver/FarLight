#include <gtest/gtest.h>
#include <FarLight/WindowSystem/WindowProps.h>
#include <FarLight/WindowSystem/Window.h>

using namespace FarLight;

class ExampleWindowTest
	: public Window
{
public:
	explicit ExampleWindowTest(const WindowProps& props)
		: isVSync(true) { }

	virtual void OnUpdate() override { }
	virtual unsigned int GetWidth() const override { return 14; }
	virtual unsigned int GetHeight() const override { return 27; }
	virtual void SetEventCallback(const EventCallbackFunction& callback) override { }
	virtual void SetVSync(bool enabled) override { isVSync = enabled; }
	virtual bool IsVSync() const override { return isVSync; }
	virtual std::shared_ptr<void> GetNativeWindow() override { return std::shared_ptr<void>(); }

private:
	bool isVSync = true;
};

class WindowTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		w1 = new ExampleWindowTest(WindowProps());
		w2 = new ExampleWindowTest(WindowProps("Testing1"));
		w3 = new ExampleWindowTest(WindowProps("Testing2", 12345));
		w4 = new ExampleWindowTest(WindowProps("Testing3", 67890, 12345));
	}

	void TearDown() override
	{
		delete w1;
		delete w2;
		delete w3;
		delete w4;
	}

	ExampleWindowTest* w1;
	ExampleWindowTest* w2;
	ExampleWindowTest* w3;
	ExampleWindowTest* w4;
};

TEST_F(WindowTest, GetWidth)
{
	EXPECT_EQ(w1->GetWidth() == 14, true);
	EXPECT_EQ(w2->GetWidth() == 15, false);
}

TEST_F(WindowTest, GetHeight)
{
	EXPECT_EQ(w1->GetHeight() == 27, true);
	EXPECT_EQ(w2->GetHeight() == 25, false);
}

TEST_F(WindowTest, VSync)
{
	EXPECT_EQ(w1->IsVSync(), true);
	w1->SetVSync(true);
	EXPECT_EQ(w1->IsVSync(), true);
	w1->SetVSync(false);
	EXPECT_EQ(w1->IsVSync(), false);
	w1->SetVSync(true);
	EXPECT_EQ(w1->IsVSync(), true);
	w1->SetVSync(false);
	EXPECT_EQ(w1->IsVSync(), false);

	EXPECT_EQ(w2->IsVSync(), true);
	w2->SetVSync(true);
	EXPECT_EQ(w2->IsVSync(), true);
	w2->SetVSync(false);
	EXPECT_EQ(w2->IsVSync(), false);
	w2->SetVSync(true);
	EXPECT_EQ(w2->IsVSync(), true);
	w2->SetVSync(false);
	EXPECT_EQ(w2->IsVSync(), false);

	EXPECT_EQ(w3->IsVSync(), true);
	w3->SetVSync(true);
	EXPECT_EQ(w3->IsVSync(), true);
	w3->SetVSync(false);
	EXPECT_EQ(w3->IsVSync(), false);
	w3->SetVSync(true);
	EXPECT_EQ(w3->IsVSync(), true);
	w3->SetVSync(false);
	EXPECT_EQ(w3->IsVSync(), false);

	EXPECT_EQ(w4->IsVSync(), true);
	w4->SetVSync(true);
	EXPECT_EQ(w4->IsVSync(), true);
	w4->SetVSync(false);
	EXPECT_EQ(w4->IsVSync(), false);
	w4->SetVSync(true);
	EXPECT_EQ(w4->IsVSync(), true);
	w4->SetVSync(false);
	EXPECT_EQ(w4->IsVSync(), false);
}