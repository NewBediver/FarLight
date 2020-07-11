#include <gtest/gtest.h>
#include <FarLight/WindowSystem/WindowProps.h>
#include <FarLight/Platform/Windows/WindowSystem/WindowsWindow.h>

using namespace FarLight;

class WindowsWindowTest
	: public ::testing::Test
{
public:
	void SetUp() override
	{
		w1 = new WindowsWindow(WindowProps());
		w2 = new WindowsWindow(WindowProps("Testing1"));
		w3 = new WindowsWindow(WindowProps("Testing2", 12345));
		w4 = new WindowsWindow(WindowProps("Testing3", 67890, 12345));

		w5 = Window::Create();
		w6 = Window::Create(WindowProps("Testing1"));
		w7 = Window::Create(WindowProps("Testing2", 12345));
		w8 = Window::Create(WindowProps("Testing3", 67890, 12345));
	}

	void TearDown() override
	{
		delete w1;
		delete w2;
		delete w3;
		delete w4;
	}

	WindowsWindow* w1;
	WindowsWindow* w2;
	WindowsWindow* w3;
	WindowsWindow* w4;
	std::shared_ptr<Window> w5;
	std::shared_ptr<Window> w6;
	std::shared_ptr<Window> w7;
	std::shared_ptr<Window> w8;
};

TEST_F(WindowsWindowTest, GetWidth)
{
	EXPECT_EQ(w1->GetWidth(), 1280);
	EXPECT_EQ(w2->GetWidth(), 1280);
	EXPECT_EQ(w3->GetWidth(), 12345);
	EXPECT_EQ(w4->GetWidth(), 67890);
	EXPECT_EQ(w5->GetWidth(), 1280);
	EXPECT_EQ(w6->GetWidth(), 1280);
	EXPECT_EQ(w7->GetWidth(), 12345);
	EXPECT_EQ(w8->GetWidth(), 67890);
}

TEST_F(WindowsWindowTest, GetHeight)
{
	EXPECT_EQ(w1->GetHeight(), 720);
	EXPECT_EQ(w2->GetHeight(), 720);
	EXPECT_EQ(w3->GetHeight(), 720);
	EXPECT_EQ(w4->GetHeight(), 12345);
	EXPECT_EQ(w5->GetHeight(), 720);
	EXPECT_EQ(w6->GetHeight(), 720);
	EXPECT_EQ(w7->GetHeight(), 720);
	EXPECT_EQ(w8->GetHeight(), 12345);
}

TEST_F(WindowsWindowTest, VSync)
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

	EXPECT_EQ(w5->IsVSync(), true);
	w5->SetVSync(true);
	EXPECT_EQ(w5->IsVSync(), true);
	w5->SetVSync(false);
	EXPECT_EQ(w5->IsVSync(), false);
	w5->SetVSync(true);
	EXPECT_EQ(w5->IsVSync(), true);
	w5->SetVSync(false);
	EXPECT_EQ(w5->IsVSync(), false);

	EXPECT_EQ(w6->IsVSync(), true);
	w6->SetVSync(true);
	EXPECT_EQ(w6->IsVSync(), true);
	w6->SetVSync(false);
	EXPECT_EQ(w6->IsVSync(), false);
	w6->SetVSync(true);
	EXPECT_EQ(w6->IsVSync(), true);
	w6->SetVSync(false);
	EXPECT_EQ(w6->IsVSync(), false);

	EXPECT_EQ(w7->IsVSync(), true);
	w7->SetVSync(true);
	EXPECT_EQ(w7->IsVSync(), true);
	w7->SetVSync(false);
	EXPECT_EQ(w7->IsVSync(), false);
	w7->SetVSync(true);
	EXPECT_EQ(w7->IsVSync(), true);
	w7->SetVSync(false);
	EXPECT_EQ(w7->IsVSync(), false);

	EXPECT_EQ(w8->IsVSync(), true);
	w8->SetVSync(true);
	EXPECT_EQ(w8->IsVSync(), true);
	w8->SetVSync(false);
	EXPECT_EQ(w8->IsVSync(), false);
	w8->SetVSync(true);
	EXPECT_EQ(w8->IsVSync(), true);
	w8->SetVSync(false);
	EXPECT_EQ(w8->IsVSync(), false);
}