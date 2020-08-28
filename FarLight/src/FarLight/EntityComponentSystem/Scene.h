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

		explicit Scene() = default;

		Entity CreateEntity(const std::string& name = std::string()) noexcept;
		void DestroyEntity(const Entity& entity) noexcept;

		template<typename... Components>
		std::vector<Entity> GetEntities() noexcept
		{
			std::vector<Entity> res;
			auto view = m_Registry.view<Components...>();
			for (auto entity : view) {
				res.emplace_back(this, entity);
			}
			return res;
		}

		void OnUpdate(const Timestep& ts) noexcept;
		void OnViewportResize(unsigned width, unsigned height) noexcept;

	private:
		entt::registry m_Registry;

		friend class Entity;
	};
}