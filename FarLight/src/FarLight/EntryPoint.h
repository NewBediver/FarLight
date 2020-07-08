#pragma once

#include "Core.h"
#include "Application.h"
#include "Logger.h"

#ifdef FL_PLATFORM_WINDOWS

extern std::shared_ptr<FarLight::Application> FarLight::CreateApplication();

int main(int args, char** argv)
{
	FarLight::Logger::Init();
	FL_CORE_INFO("Logger initialized.");

	auto app = FarLight::CreateApplication();
	FL_INFO("Client application initialized.");

	app->Run();
}

#endif