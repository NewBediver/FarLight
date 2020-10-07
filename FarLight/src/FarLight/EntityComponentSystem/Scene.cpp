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

#include "FarLight/BasicFunctionality/Timer/Timer.h"

#include <glm/gtc/matrix_transform.hpp>

namespace FarLight
{
    Ref<Entity> Scene::CreateEntity() noexcept
    {
        Ref<Entity> entity = CreateRef<Entity>(this, m_Registry.create());
        while (HasEntity(entity->GetId<boost::uuids::uuid>())) entity = CreateRef<Entity>(this, m_Registry.create());

        m_IdToEntity.emplace(entity->GetId<boost::uuids::uuid>(), entity->m_Handle);

        entity->AddComponent<TagComponent>();
        entity->AddComponent<TransformComponent>();
        
        return entity;
    }

    Ref<Entity> Scene::CreateEntity(const boost::uuids::uuid& id) noexcept
    {
        Ref<Entity> entity = CreateRef<Entity>(id, this, m_Registry.create());
        if (HasEntity(id))
        {
            FL_CORE_WARN("Scene already contains entity with id = \"{0}\"!", entity->GetId<std::string>());
            m_IdToEntity.find(id)->second = entity->m_Handle;
        }
        else
        {
            m_IdToEntity.emplace(id, entity->m_Handle);
        }

        entity->AddComponent<TagComponent>();
        entity->AddComponent<TransformComponent>();

        return entity;
    }

    void Scene::AddEntity(Ref<Entity> entity) noexcept
    {
        if (HasEntity(entity->GetId<boost::uuids::uuid>()))
        {
            FL_CORE_WARN("Scene already contains entity with id = \"{0}\"!", entity->GetId<std::string>());
            m_IdToEntity.find(entity->GetId<boost::uuids::uuid>())->second = entity->m_Handle;
        }
        else
        {
            m_IdToEntity.emplace(entity->GetId<boost::uuids::uuid>(), entity->m_Handle);
        }
    }

    Ref<Entity> Scene::GetEntity(const boost::uuids::uuid& id) noexcept
    {
        if (m_IdToEntity.find(id) != m_IdToEntity.end())
        {
            Ref<Entity> entity = CreateRef<Entity>(id, this, m_IdToEntity[id]);
            return entity;
        }

        FL_CORE_WARN("Scene doesn't contain entity with id = \"{0}\"!", boost::lexical_cast<std::string>(id));
        return nullptr;
    }

    bool Scene::HasEntity(const boost::uuids::uuid& id) const noexcept
    {
        return m_IdToEntity.find(id) != m_IdToEntity.end();
    }

    void Scene::EraseEntity(const boost::uuids::uuid& id) noexcept
    {
        if (HasEntity(id))
        {
            m_Registry.destroy(m_IdToEntity[id]);
            m_IdToEntity.erase(id);
        }
    }

    const std::unordered_map<boost::uuids::uuid, entt::entity, boost::hash<boost::uuids::uuid>>& Scene::GetEntityMap() noexcept
    {
        return m_IdToEntity;
    }

    void Scene::CreateSquare() noexcept
    {
        auto tmp = CreateEntity();
        tmp->GetComponent<TagComponent>().SetTag("Square");
        tmp->AddComponent<RenderComponent>();
    }

    void Scene::CreateCamera() noexcept
    {
        auto tmp = CreateEntity();
        tmp->GetComponent<TagComponent>().SetTag("Camera");
        tmp->AddComponent<CameraComponent>(1280, 720, false);
    }



    void Scene::OnUpdate(const Timestep& ts) noexcept
    {
        //FL_CORE_TRACE("My timer: {0} s. GLFW Timer: {1} s.", Timer::GetInstance().GetDelta(), ts);

        // execute scripts
        {
            m_Registry.view<NativeScriptComponent>().each([&](auto entity, auto& nativeScriptComp)
                {
                    if (nativeScriptComp.Script == nullptr)
                    {
                        nativeScriptComp.Bind<ScriptableBehaviour>(CreateRef<Entity>(this, entity));
                        //nativeScriptComp.m_Instanciate(nativeScriptComp);
                        //nativeScriptComp.Script->m_Entity = CreateRef<Entity>()Entity(this, entity);
                        nativeScriptComp.Script->OnCreate();
                    }
                    nativeScriptComp.Script->OnUpdate(ts);
                });
        }

        // Find main camera and get it's transform
        CameraComponent* mainCamera = nullptr;
        glm::vec3 cameraPosition = glm::vec3(0.0f);
        glm::vec3 cameraRotation = glm::vec3(0.0f);
        m_Registry.view<TransformComponent, CameraComponent>().each([&](auto entity, auto& transformComp, auto& cameraComp)
            {
                if (cameraComp.IsPrimary())
                {
                    mainCamera = &cameraComp;
                    cameraPosition = transformComp.GetPosition();
                    cameraRotation = transformComp.GetRotation();
                    return;
                }
            });

        // Render scene
        {
            if (mainCamera)
                mainCamera->GetCamera()->SetViewMatrix(cameraPosition, cameraRotation);
            else if (m_IsRenderViewportFocused && m_IsRenderViewportHovered)
                m_EditorCameraController.OnUpdate(ts);

            Ref<Camera> camera = (mainCamera ? mainCamera->GetCamera() : m_EditorCameraController.GetCamera());

            RenderCommand::SetClearColor(camera->GetBackgroundColor());
            RenderCommand::Clear();

            Renderer2D::BeginScene(camera);

            m_Registry.view<TransformComponent, RenderComponent>().each([&](auto entity, auto& transformComp, auto& renderComp)
                {
                    Renderer2D::DrawRotatedQuad(transformComp.GetPosition(), glm::vec2(transformComp.GetSize()), glm::radians(transformComp.GetRotation().z), renderComp.GetColor());
                });

            Renderer2D::EndScene();
        }
    }

    void Scene::OnViewportResize(unsigned width, unsigned height) noexcept
    {
        m_Registry.view<CameraComponent>().each([&](auto entity, auto& cameraComp)
            {
                if (!cameraComp.IsFixedAspectRatio())
                {
                    cameraComp.GetCamera()->SetResolutionWidth(width);
                    cameraComp.GetCamera()->SetResolutionHeight(height);
                }
            });

        m_EditorCameraController.OnResize(width, height);
    }

    void Scene::OnEvent(Event& e) noexcept
    {
        if (m_IsRenderViewportFocused && m_IsRenderViewportHovered)
            m_EditorCameraController.OnEvent(e);
    }
}
