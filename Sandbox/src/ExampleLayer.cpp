#include "ExampleLayer.h"

ExampleLayer::ExampleLayer(std::string name)
	: Layer(name)
{ }

void ExampleLayer::OnUpdate()
{
	FL_INFO("ExampleLayer::OnUpdate()")
}

void ExampleLayer::OnAttach()
{
	FL_INFO("ExampleLayer::OnAttach()")
}

void ExampleLayer::OnDetach()
{
	FL_INFO("ExampleLayer::OnDetach()")
}

void ExampleLayer::OnEvent(Event& event)
{
	FL_TRACE("ExampleLayer::OnEvent({0})", event);
}
