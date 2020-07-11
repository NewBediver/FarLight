#include <FarLight.h>

#include <FarLight/EntryPoint.h>

std::shared_ptr<FarLight::Application> FarLight::CreateApplication()
{
	auto app = FarLight::Application::GetInstance();
	return app;
}