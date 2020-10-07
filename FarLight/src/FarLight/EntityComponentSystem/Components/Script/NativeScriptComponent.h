#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/EntityComponentSystem/Components/Script/ScriptableBehaviour.h"
#include "FarLight/EntityComponentSystem/Entity.h"

namespace FarLight
{
    class NativeScriptComponent
    {
        friend class Scene;

    public:
        Scope<ScriptableBehaviour> Script;

        template<typename T>
        void Bind(Ref<Entity> entity)
        {
            FL_CORE_ASSERT(Script == nullptr, "Script has already been binded! Unbind it first!");

            m_Instanciate = [](NativeScriptComponent& nsComp, Ref<Entity> entity) { nsComp.Script = CreateScope<T>(entity); };
            m_Destroy = [](NativeScriptComponent& nsComp) { nsComp.Unbind(); };
        }

        void Unbind()
        {
            Script.reset();
            m_Instanciate = nullptr;
            m_Destroy = nullptr;
        }

    private:
        void(*m_Instanciate)(NativeScriptComponent&, Ref<Entity>);
        void(*m_Destroy)(NativeScriptComponent&);
    };
}
