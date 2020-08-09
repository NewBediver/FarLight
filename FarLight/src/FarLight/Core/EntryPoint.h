#pragma once

#include "FarLight/Core/Core.h"
#include "FarLight/Core/Application.h"
#include "FarLight/LogSystem/Logger.h"
#include "FarLight/Profiling/Instrumentor.h"

#ifdef FL_PLATFORM_WINDOWS

extern FarLight::Application& FarLight::CreateApplication() noexcept;

int main(int args, char** argv)
{
	FL_PROFILE_BEGIN_SESSION("Startup", "FarLightProfile-Startup.json");
	FarLight::Logger::Init();
	FL_CORE_INFO("[Logger] initialized.");
	auto& app = FarLight::CreateApplication();
	FL_PROFILE_END_SESSION();

	FL_PROFILE_BEGIN_SESSION("Runtime", "FarLightProfile-Runtime.json");
	app.Run();
	FL_PROFILE_END_SESSION();	
}

#endif