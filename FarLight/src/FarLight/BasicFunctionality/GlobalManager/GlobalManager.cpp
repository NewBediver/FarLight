#include "flpch.h"
#include "GlobalManager.h"

#include "FarLight/Profiling/Instrumentor.h"
#include "FarLight/LogSystem/Logger.h"
#include "FarLight/VirtualFileSystem/FileSystem.h"
#include "FarLight/ConfigurationSystem/ConfigurationManager.h"
#include "FarLight/ResourceSystem/ResourceManager.h"
#include "FarLight/InputSystem/InputManager.h"
#include "FarLight/BasicFunctionality/Application.h"
#include "FarLight/RenderSystem/Renderer/Renderer2D.h"
#include "FarLight/EntityComponentSystem/SceneManager.h"

namespace FarLight
{
    void GlobalManager::GlobalInitialization() const noexcept
    {
        InitializeProfiler();
        FL_PROFILE_BEGIN_SESSION("Startup", "FarLightProfile-Startup.json");
        InitializeLogger();

        InitializeFileSystem();
        InitializeConfiguration();
        InitializeApplication();
        InitializeRender();
        InitializeResource();
        InitializeInput();
        InitializeScene();

        // Application
        //FarLight::Application::Create();
        //FL_CORE_INFO("[Application] is initialized.");

        // TODO: use Sigleton base class
        //Renderer2D::Init();
        //FL_CORE_INFO("[Renderer2D] is initialized.");

        FL_PROFILE_END_SESSION();
    }

    // Must be in reverse order
    void GlobalManager::GlobalTermination() const noexcept
    {
        FL_PROFILE_BEGIN_SESSION("Termination", "FarLightProfile-Termination.json");

        // TODO: use Sigleton base class
        //Renderer2D::Shutdown();
        //FL_CORE_INFO("[Renderer2D] is destoyed.");

        // Application
        //FarLight::Application::Destroy();
        //FL_CORE_INFO("[Application] is destoyed.");

        TerminateInput();
        TerminateResource();
        TerminateRender();
        TerminateApplication();
        TerminateConfiguration();
        TerminateFileSystem();
        TerminateScene();

        TerminateLogger();
        FL_PROFILE_END_SESSION();
        TerminateProfiler();
    }

    void GlobalManager::InitializeLogger() const noexcept
    {
        FarLight::Logger::Create();
        FarLight::Logger::GetInstance().Initialize();
        FL_CORE_INFO("[Logger] is initialized.");
    }

    void GlobalManager::TerminateLogger() const noexcept
    {
        FL_CORE_INFO("[Logger] is destroyed.");
        FarLight::Logger::Destroy();
    }


    void GlobalManager::InitializeProfiler() const noexcept
    {
        FarLight::Instrumentor::Create();
    }

    void GlobalManager::TerminateProfiler() const noexcept
    {
        FarLight::Instrumentor::Destroy();
    }


    void GlobalManager::InitializeFileSystem() const noexcept
    {
        FarLight::FileSystem::Create();
        FL_CORE_INFO("[File System] is initialized.");
    }

    void GlobalManager::TerminateFileSystem() const noexcept
    {
        FarLight::FileSystem::Destroy();
        FL_CORE_INFO("[File System] is destroyed.");
    }


    void GlobalManager::InitializeConfiguration() const noexcept
    {
        FarLight::ConfigurationManager::Create();
        FL_CORE_INFO("[Configuration Manager] is initialized.");
    }

    void GlobalManager::TerminateConfiguration() const noexcept
    {
        FarLight::ConfigurationManager::Destroy();
        FL_CORE_INFO("[Configuration Manager] is destroyed.");
    }


    void GlobalManager::InitializeResource() const noexcept
    {
        FarLight::ResourceManager::Create();
        FL_CORE_INFO("[Resource Manager] is initialized.");
    }

    void GlobalManager::TerminateResource() const noexcept
    {
        FarLight::ResourceManager::Destroy();
        FL_CORE_INFO("[Resource Manager] is destroyed.");
    }


    void GlobalManager::InitializeInput() const noexcept
    {
        FarLight::InputManager::Create();
        FL_CORE_INFO("[InputManager] is initialized.");
    }

    void GlobalManager::TerminateInput() const noexcept
    {
        FarLight::InputManager::Destroy();
        FL_CORE_INFO("[InputManager] is destroyed.");
    }


    void GlobalManager::InitializeApplication() const noexcept
    {
        FarLight::Application::Create();
        FL_CORE_INFO("[Application] is initialized.");
    }

    void GlobalManager::TerminateApplication() const noexcept
    {
        FarLight::Application::Destroy();
        FL_CORE_INFO("[Application] is destoyed.");
    }


    void GlobalManager::InitializeRender() const noexcept
    {
        Renderer2D::Init();
        FL_CORE_INFO("[Renderer2D] is initialized.");
    }

    void GlobalManager::TerminateRender() const noexcept
    {
        Renderer2D::Shutdown();
        FL_CORE_INFO("[Renderer2D] is destoyed.");
    }

    void GlobalManager::InitializeScene() const noexcept
    {
        SceneManager::Create();
        FL_CORE_INFO("[Scene Manager] is initialized.");
    }

    void GlobalManager::TerminateScene() const noexcept
    {
        SceneManager::Destroy();
        FL_CORE_INFO("[Scene manager] is destoyed.");
    }
}


