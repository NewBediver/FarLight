#include <Farlight.h>

#include <FarLight/Core/EntryPoint.h>

#include "Layers/ExampleLayer.h"
#include "Layers/Example2DRenderer.h"

const FarLight::Scope<FarLight::Application>& FarLight::CreateApplication()
{
	const auto& app = FarLight::Application::GetInstance();
	//app->PushLayer(CreateScope<ExampleLayer>());
	app->PushLayer(CreateScope<Example2DRenderer>());
	return app;
}