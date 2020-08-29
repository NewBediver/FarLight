#pragma once

#include "FarLight/Core/Core.h"
#include "FarLight/EntityComponentSystem/ScriptableBehaviour.h"
#include "FarLight/EntityComponentSystem/Entity.h"

namespace FarLight
{
	class NativeScriptComponent
	{
	public:
		Scope<ScriptableBehaviour> Script;

		template<typename T>
		void Bind()
		{
			FL_CORE_ASSERT(Script == nullptr, "Script has already been binded! Unbind it first!");

			m_Instanciate = [](NativeScriptComponent& nsComp) { nsComp.Script = CreateScope<T>(); };
			m_Destroy = [](NativeScriptComponent& nsComp) { nsComp.Unbind(); };
		}

		void Unbind()
		{
			Script.reset();
			m_Instanciate = nullptr;
			m_Destroy = nullptr;
		}

	private:
		void(*m_Instanciate)(NativeScriptComponent&);
		void(*m_Destroy)(NativeScriptComponent&);

		friend class Scene;
	};
}