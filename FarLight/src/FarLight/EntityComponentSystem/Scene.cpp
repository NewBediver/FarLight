// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Components/Tag/TagComponent.h"
#include "Components/Transform/TransformComponent.h"
#include "Components/Render/RenderComponent.h"
#include "Components/Camera/Camera2DComponent.h"
#include "Components/Script/NativeScriptComponent.h"

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
		// execute scripts
		{
			m_Registry.view<NativeScriptComponent>().each([&](auto entity, auto& nativeScriptComp)
				{
					if (nativeScriptComp.Script == nullptr)
					{
						nativeScriptComp.m_Instanciate(nativeScriptComp);
						nativeScriptComp.Script->m_Entity = Entity(this, entity);
						nativeScriptComp.Script->OnCreate();
					}
					nativeScriptComp.Script->OnUpdate(ts);
				});
		}

		// Find main camera and get it's transform
		Render2DCamera* mainCamera = nullptr;
		glm::mat4 cameraTransform = glm::mat4(1.0f);
		float cameraRotation = 0.0f;
		{
			auto view = m_Registry.view<TransformComponent, Camera2DComponent>();
			for (auto entity : view)
			{
				auto& [transformComp, cameraComp] = view.get<TransformComponent, Camera2DComponent>(entity);
				if (cameraComp.IsPrimary)
				{
					mainCamera = &cameraComp.Camera;
					cameraTransform = transformComp.GetTransformationMatrix();
				}
			}
		}

		// Render scene
		if (mainCamera)
		{
			Renderer2D::BeginScene(glm::inverse(cameraTransform), mainCamera->GetProjection());

			auto view = m_Registry.view<TransformComponent, RenderComponent>();
			for (auto entity : view)
			{
				auto& [transformComp, renderComp] = view.get<TransformComponent, RenderComponent>(entity);
				Renderer2D::DrawRotatedQuad(transformComp.Position, transformComp.Size, transformComp.Rotation, renderComp.Color);
			}

			Renderer2D::EndScene();
		}
	}

	void Scene::OnViewportResize(unsigned width, unsigned height) noexcept
	{
		auto view = m_Registry.view<Camera2DComponent>();
		for (auto entity : view)
		{
			auto& cameraComp = view.get<Camera2DComponent>(entity);
			if (!cameraComp.IsFixedAspectRatio)
			{
				cameraComp.SetAspectRatio(width, height);
			}
		}
	}
}