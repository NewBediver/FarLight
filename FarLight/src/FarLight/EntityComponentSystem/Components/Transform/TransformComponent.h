#pragma once

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/EntityComponentSystem/Interfaces/OnUIDrawable.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class TransformComponent final
        : public EngineObject
        , public OnUIDrawable
    {
    public:
        explicit TransformComponent(boost::uuids::uuid id, const glm::vec3& position = glm::vec3(0.0f), const glm::vec3& size = glm::vec3(0.0f), const glm::vec3& rotation = glm::vec3(0.0f)) noexcept
            : EngineObject(std::move(id))
            , m_Position(position)
            , m_Size(size)
            , m_Rotation(rotation)
            , m_IsDataChanged(true)
            , m_Transform(glm::mat4(0.0f))
        {
            FL_CORE_ASSERT(size.x >= 0.0f && size.y >= 0.0f && size.z >= 0.0f, "Size cannot be less than zero!");
        }

        explicit TransformComponent(const glm::vec3& position = glm::vec3(0.0f), const glm::vec3& size = glm::vec3(0.0f), const glm::vec3& rotation = glm::vec3(0.0f)) noexcept
            : m_Position(position)
            , m_Size(size)
            , m_Rotation(rotation)
            , m_IsDataChanged(true)
            , m_Transform(glm::mat4(0.0f))
        {
            FL_CORE_ASSERT(size.x >= 0.0f && size.y >= 0.0f && size.z >= 0.0f, "Size cannot be less than zero!");
        }

        const glm::mat4& GetTransformationMatrix() noexcept;

        const glm::vec3& GetPosition() const noexcept { return m_Position; }
        void SetPosition(const glm::vec3& position) noexcept;

        const glm::vec3& GetSize() const noexcept { return m_Size; }
        void SetSize(const glm::vec3& size) noexcept;

        const glm::vec3& GetRotation() const noexcept { return m_Rotation; }
        void SetRotation(const glm::vec3& rotation) noexcept;

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        void RecalculateTransformMatix() noexcept;

        glm::vec3 m_Position;
        glm::vec3 m_Size;
        // Pitch, Yaw, Roll
        glm::vec3 m_Rotation;

        bool m_IsDataChanged;
        glm::mat4 m_Transform;
    };
}
