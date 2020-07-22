#include <Farlight.h>

#include <FarLight/EntryPoint.h>

#include "Layers/ExampleLayer.h"

const FarLight::Scope<FarLight::Application>& FarLight::CreateApplication()
{
	const auto& app = FarLight::Application::GetInstance();
	app->PushLayer(Ref<ExampleLayer>(new ExampleLayer()));
	return app;
}