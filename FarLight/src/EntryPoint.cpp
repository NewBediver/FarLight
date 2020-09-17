#include "flpch.h"

#include "FarLight/BasicFunctionality/Application.h"

#include "FarLight/BasicFunctionality/GlobalManager/GlobalManager.h"

#include "FarLight/EditorSystem/Layers/EditorLayer.h"

#ifdef FL_PLATFORM_WINDOWS

int main(int args, char** argv)
{
    FarLight::GlobalManager::Create();
    FarLight::GlobalManager::GetInstance().GlobalInitialization();
    
    FL_PROFILE_BEGIN_SESSION("Runtime", "FarLightProfile-Runtime.json");
    FarLight::Application::GetInstance().PushLayer(FarLight::CreateRef<FarLight::EditorLayer>());
    FarLight::Application::GetInstance().Run();
    FL_PROFILE_END_SESSION();

    FarLight::GlobalManager::GetInstance().GlobalTermination();
    FarLight::GlobalManager::Destroy();
}

#else
    #error "Engine is Windows only now!"
#endif
