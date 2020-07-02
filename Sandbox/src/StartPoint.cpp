#include <FarLight/EntryPoint.h>
#include <FarLight/Application.h>
#include <FarLight/LayerSystem/EngineLayers/ImGuiLayer.h>

#include "ExampleLayer.h"

FarLight::Application* FarLight::CreateApplication()
{
	FarLight::Application& app = FarLight::Application::GetInstance();
	app.PushLayer(new ExampleLayer("My layer!"));
	app.PushLayer(new ImGuiLayer());
	return &app;
}