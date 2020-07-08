#include "ExampleLayer.h"

#include <FarLight.h>

#include "imgui.h"

ExampleLayer::ExampleLayer()
	: Layer("ExampleLayer")
{
}

void ExampleLayer::OnAttach() const
{
}

void ExampleLayer::OnDetach() const
{
}

void ExampleLayer::OnUpdate()
{
}

void ExampleLayer::OnUserInterfaceRender()
{
	ImGui::Begin("Test");
	ImGui::Text("Hello world!");
	ImGui::End();
}

void ExampleLayer::OnEvent(Event& event)
{
}
