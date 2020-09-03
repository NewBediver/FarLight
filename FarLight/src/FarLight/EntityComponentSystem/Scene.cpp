// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/EntityComponentSystem/Components/Tag/TagComponent.h"
#include "FarLight/EntityComponentSystem/Components/Transform/TransformComponent.h"
#include "FarLight/EntityComponentSystem/Components/Render/RenderComponent.h"
#include "FarLight/EntityComponentSystem/Components/Camera/CameraComponent.h"
#include "FarLight/EntityComponentSystem/Components/Script/NativeScriptComponent.h"

#include "FarLight/EntityComponentSystem/Scene.h"
#include "FarLight/EntityComponentSystem/Entity.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
    Ref<Scene> Scene::Create() noexcept
    {
        return CreateRef<Scene>();
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
            auto view = m_Registry.view<TransformComponent, CameraComponent>();
            for (auto entity : view)
            {
                auto& [transformComp, cameraComp] = view.get<TransformComponent, CameraComponent>(entity);
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
                Renderer2D::DrawRotatedQuad(transformComp.GetPosition(), glm::vec2(transformComp.GetSize()), transformComp.GetRotation().z, renderComp.GetColor());
            }

            Renderer2D::EndScene();
        }
    }

    void Scene::OnViewportResize(unsigned width, unsigned height) noexcept
    {
        auto view = m_Registry.view<CameraComponent>();
        for (auto entity : view)
        {
            auto& cameraComp = view.get<CameraComponent>(entity);
            if (!cameraComp.IsFixedAspectRatio)
            {
                cameraComp.SetAspectRatio(width, height);
            }
        }
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

    void Scene::CreateSquare() noexcept
    {
        auto tmp = CreateEntity("Square");
        tmp.AddComponent<RenderComponent>();
    }

    void Scene::CreateCamera() noexcept
    {
        auto tmp = CreateEntity("Camera");
        tmp.AddComponent<CameraComponent>(16, 9, false);
    }
}
