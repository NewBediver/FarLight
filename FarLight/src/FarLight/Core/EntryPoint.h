#pragma once

#include "Core.h"
#include "FarLight/LogSystem/Logger.h"
#include "FarLight/Application.h"

#ifdef FL_PLATFORM_WINDOWS

extern const FarLight::Scope<FarLight::Application>& FarLight::CreateApplication();

int main(int args, char** argv)
{
	FarLight::Logger::Init();
	FL_CORE_INFO("Logger initialized.");

	const auto& app = FarLight::CreateApplication();
	FL_INFO("Client application initialized.");

	app->Run();
}

#endif