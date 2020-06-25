#pragma once

#ifdef FL_PLATFORM_WINDOWS

extern FarLight::Application* FarLight::CreateApplication();

int main(int args, char** argv)
{
	FarLight::Logger::Init();
	FL_CORE_INFO("Logger initialized.");

	auto app = FarLight::CreateApplication();
	FL_INFO("Client application initialized.");

	app->Run();
	delete app;
}

#endif