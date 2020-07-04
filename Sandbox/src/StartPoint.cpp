#include <FarLight/EntryPoint.h>
#include <FarLight/Application.h>
#include <FarLight/LayerSystem/EngineLayers/ImGuiLayer.h>

FarLight::Application* FarLight::CreateApplication()
{
	FarLight::Application& app = FarLight::Application::GetInstance();
	app.PushLayer(std::make_shared<ImGuiLayer>());
	return &app;
}