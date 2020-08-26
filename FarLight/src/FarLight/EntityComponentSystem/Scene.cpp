// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Components/Tag/TagComponent.h"
#include "Components/Transform/TransformComponent.h"
#include "Components/Render/RenderComponent.h"
#include "Components/Camera/Camera2DComponent.h"

#include "Scene.h"
#include "Entity.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>

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
		RenderCamera* mainCamera = nullptr;
		glm::mat4 cameraTransform = glm::mat4(1.0f);
		float cameraRotation = 0.0f;
		{
			auto group = m_Registry.view<TransformComponent, Camera2DComponent>();
			for (auto entity : group)
			{
				auto& [transformComp, cameraComp] = group.get<TransformComponent, Camera2DComponent>(entity);
				if (cameraComp.IsPrimary)
				{
					mainCamera = &cameraComp.Camera;
					cameraTransform = transformComp.GetTransformationMatrix();
				}
			}
		}

		if (mainCamera)
		{
			Renderer2D::BeginScene(glm::inverse(cameraTransform), mainCamera->GetProjection());

			auto group = m_Registry.view<TransformComponent, RenderComponent>();
			for (auto entity : group)
			{
				auto& [transformComp, renderComp] = group.get<TransformComponent, RenderComponent>(entity);
				Renderer2D::DrawRotatedQuad(transformComp.Position, transformComp.Size, transformComp.Rotation, renderComp.Color);
			}

			Renderer2D::EndScene();
		}
	}
}