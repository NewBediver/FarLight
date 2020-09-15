#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/BasicFunctionality/Application.h"

#include "FarLight/LogSystem/Logger.h"

#include "FarLight/InputSystem/Input.h"

#include "FarLight/Profiling/Instrumentor.h"

#include "FarLight/VirtualFileSystem/FileSystem.h"

#include "FarLight/EditorSystem/Layers/EditorLayer.h"

#ifdef FL_PLATFORM_WINDOWS

//extern FarLight::Application& FarLight::CreateApplication() noexcept;

int main(int args, char** argv)
{
    FL_PROFILE_BEGIN_SESSION("Startup", "FarLightProfile-Startup.json");
    FarLight::Logger::Initialize();

    FarLight::Input::Create();

    FarLight::FileSystem::GetInstance().Initialize();
    FL_CORE_INFO("[Logger] initialized.");
    //auto& app = FarLight::CreateApplication();

    auto& app = FarLight::Application::GetInstance();
    app.PushLayer(FarLight::CreateRef<FarLight::EditorLayer>());

    FL_PROFILE_END_SESSION();

    FL_PROFILE_BEGIN_SESSION("Runtime", "FarLightProfile-Runtime.json");
    app.Run();
    FL_PROFILE_END_SESSION();
}

#endif
