#include "flpch.h"
#include "GlobalManager.h"

#include "FarLight/Profiling/Instrumentor.h"
#include "FarLight/LogSystem/Logger.h"
#include "FarLight/VirtualFileSystem/FileSystem.h"
#include "FarLight/ConfigurationSystem/ConfigurationManager.h"
#include "FarLight/SerializationSystem/Serialization.h"
#include "FarLight/ResourceSystem/ResourceManager.h"
#include "FarLight/InputSystem/InputManager.h"
#include "FarLight/BasicFunctionality/Application.h"
#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

namespace FarLight
{
    void GlobalManager::GlobalInitialization() const noexcept
    {
        // Profiler
        FarLight::Instrumentor::Create();
        FL_PROFILE_BEGIN_SESSION("Startup", "FarLightProfile-Startup.json");

        // Logger
        FarLight::Logger::Create();
        FarLight::Logger::GetInstance().Initialize();
        FL_CORE_INFO("[Logger] is initialized.");

        // FileSystem
        FarLight::FileSystem::Create();
        FL_CORE_INFO("[File System] is initialized.");

        // Configuration Manager
        FarLight::ConfigurationManager::Create();
        FL_CORE_INFO("[Configuration Manager] is initialized.");

        // Serializer
        FarLight::Serializer::Create();
        FL_CORE_INFO("[Serializer] is initialized.");

        /////////////
        // Application
        FarLight::Application::Create();
        FL_CORE_INFO("[Application] is initialized.");

        // TODO: use Sigleton base class
        Renderer2D::Init();
        FL_CORE_INFO("[Renderer2D] is initialized.");
        /////////////

        // Resource Manager
        FarLight::ResourceManager::Create();
        FL_CORE_INFO("[Resource Manager] is initialized.");

        // InputManager
        FarLight::InputManager::Create();
        FL_CORE_INFO("[InputManager] is initialized.");

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

        // InputManager
        FarLight::InputManager::Destroy();
        FL_CORE_INFO("[InputManager] is destroyed.");

        // Resource Manager
        FarLight::ResourceManager::Destroy();
        FL_CORE_INFO("[Resource Manager] is destroyed.");

        ///////////////
        // TODO: use Sigleton base class
        Renderer2D::Shutdown();
        FL_CORE_INFO("[Renderer2D] is destoyed.");

        FarLight::Application::Destroy();
        FL_CORE_INFO("[Application] is destoyed.");
        ///////////////

        // Serializer
        FarLight::Serializer::Destroy();
        FL_CORE_INFO("[Serializer] is destroyed.");

        // Configuration Manager
        FarLight::ConfigurationManager::Destroy();
        FL_CORE_INFO("[Configuration Manager] is destroyed.");

        // FileSystem
        FarLight::FileSystem::Destroy();
        FL_CORE_INFO("[File System] is destroyed.");

        // Logger
        FL_CORE_INFO("[Logger] is destroyed.");
        FarLight::Logger::Destroy();

        // Profiler
        FL_PROFILE_END_SESSION();
        FarLight::Instrumentor::Destroy();
    }
}


