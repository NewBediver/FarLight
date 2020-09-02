#pragma once

#include "FarLight/EntityComponentSystem/Interfaces/IComponent.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class TransformComponent final
        : public IComponent
    {
    public:
        explicit TransformComponent(const glm::vec3& position = glm::vec3(0.0f), const glm::vec3& size = glm::vec3(1.0f), const glm::vec3& rotation = glm::vec3(0.0f)) noexcept;

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
        glm::vec3 m_Rotation;

        bool m_IsDataChanged;
        glm::mat4 m_Transform;
    };
}
