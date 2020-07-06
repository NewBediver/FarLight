#include <FarLight.h>

#include <FarLight/EntryPoint.h>
#include "InputLayer.h"

FarLight::Application* FarLight::CreateApplication()
{
	auto app = FarLight::Application::GetInstance();
	app->PushOverlay(std::make_shared<ImGuiLayer>());
	app->PushOverlay(std::make_shared<InputLayer>());
	return app;
}