#include <FarLight.h>

#include <FarLight/EntryPoint.h>

FarLight::Application* FarLight::CreateApplication()
{
	auto app = FarLight::Application::GetInstance();
	return app;
}