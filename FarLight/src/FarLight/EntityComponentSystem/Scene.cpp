// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Components.h"
#include "Scene.h"
#include "Entity.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

namespace FarLight
{
	Ref<Scene> Scene::Create() noexcept
	{
		return CreateRef<Scene>();
	}

	Entity Scene::CreateEntity(const std::string& name) noexcept
	{
		Entity entity(this, m_Registry.create());

		entity.AddComponent<TransformComponent>();

		if (name.empty()) entity.AddComponent<TagComponent>();
		else entity.AddComponent<TagComponent>(name);

		return entity;
	}

	void Scene::DestroyEntity(const Entity& entity) noexcept
	{
		m_Registry.destroy(entity.m_Handle);
	}

	void Scene::OnUpdate(const Timestep& ts) noexcept
	{
		auto group = m_Registry.group<TransformComponent, RendererComponent>();
		for (auto entity : group)
		{
			auto& [transformComp, renderComp] = group.get<TransformComponent, RendererComponent>(entity);
			Renderer2D::DrawRotatedQuad(transformComp.Position, transformComp.Size, transformComp.Rotation, renderComp.Color);
		}
	}
}