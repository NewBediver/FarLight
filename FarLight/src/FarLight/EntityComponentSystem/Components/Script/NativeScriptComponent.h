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

			m_Instanciate = [this]() { this->Script = CreateScope<T>(); };
			m_Destroy = [this]() { this->Unbind(); };
		}

		void Unbind()
		{
			Script.reset();
			m_Instanciate = nullptr;
			m_Destroy = nullptr;
		}

	private:
		std::function<void()> m_Instanciate;
		std::function<void()> m_Destroy;

		friend class Scene;
	};
}