#include <FarLight/EntryPoint.h>
#include <FarLight/Application.h>
#include <FarLight/LayerSystem/EngineLayers/ImGuiLayer.h>

FarLight::Application* FarLight::CreateApplication()
{
	auto app = FarLight::Application::GetInstance();
	app->PushLayer(std::make_shared<ImGuiLayer>());
	return app;
}