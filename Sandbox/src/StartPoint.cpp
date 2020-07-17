#include <FarLight/EntryPoint.h>

#include "Layers/ExampleLayer.h"

std::shared_ptr<FarLight::Application> FarLight::CreateApplication()
{
	auto app = FarLight::Application::GetInstance();
	app->PushLayer(std::make_shared<ExampleLayer>());
	return app;
}