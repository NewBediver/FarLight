#pragma once

#include "FarLight/Core/Core.h"
#include "FarLight/Core/Timestep.h"

#include <entt/entt.hpp>

namespace FarLight
{
	class Entity;

	class Scene final
	{
	public:
		static Ref<Scene> Create() noexcept;

		Scene(const Scene&) = delete;
		Scene(Scene&&) = delete;
		Scene& operator==(const Scene&) = delete;
		Scene& operator==(Scene&&) = delete;

		explicit Scene() noexcept = default;

		Entity CreateEntity(const std::string& name = std::string()) noexcept;
		void DestroyEntity(const Entity& entity) noexcept;

		void OnUpdate(const Timestep& ts) noexcept;

	private:
		entt::registry m_Registry;

		friend class Entity;
	};
}