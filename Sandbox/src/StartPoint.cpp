#include <Farlight.h>

#include <FarLight/Core/EntryPoint.h>

#include "Layers/Example2DRenderer.h"

FarLight::Application& FarLight::CreateApplication()
{
	auto& app = FarLight::Application::GetInstance();
	app.PushLayer(FarLight::CreateScope<Example2DRenderer>());
	return app;
}