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
        FL_REGISTER_SERIALIZABLE;

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
        //=Serialization part======================================
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_DERIVED(EngineObject)
               & FL_SERIALIZE_DERIVED(OnUIDrawable)
               & FL_SERIALIZE_NAMED("PositionX", m_Position.x)
               & FL_SERIALIZE_NAMED("PositionY", m_Position.y)
               & FL_SERIALIZE_NAMED("PositionZ", m_Position.z)
               & FL_SERIALIZE_NAMED("SizeX", m_Size.x)
               & FL_SERIALIZE_NAMED("SizeY", m_Size.y)
               & FL_SERIALIZE_NAMED("SizeZ", m_Size.z)
               & FL_SERIALIZE_NAMED("RotationX", m_Rotation.x)
               & FL_SERIALIZE_NAMED("RotationY", m_Rotation.y)
               & FL_SERIALIZE_NAMED("RotationZ", m_Rotation.z);
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_DERIVED(EngineObject)
               & FL_SERIALIZE_DERIVED(OnUIDrawable)
               & FL_SERIALIZE_NAMED("PositionX", m_Position.x)
               & FL_SERIALIZE_NAMED("PositionY", m_Position.y)
               & FL_SERIALIZE_NAMED("PositionZ", m_Position.z)
               & FL_SERIALIZE_NAMED("SizeX", m_Size.x)
               & FL_SERIALIZE_NAMED("SizeY", m_Size.y)
               & FL_SERIALIZE_NAMED("SizeZ", m_Size.z)
               & FL_SERIALIZE_NAMED("RotationX", m_Rotation.x)
               & FL_SERIALIZE_NAMED("RotationY", m_Rotation.y)
               & FL_SERIALIZE_NAMED("RotationZ", m_Rotation.z);
        }
        //=========================================================

        void RecalculateTransformMatix() noexcept;

        glm::vec3 m_Position;
        glm::vec3 m_Size;
        // Pitch, Yaw, Roll
        glm::vec3 m_Rotation;

        bool m_IsDataChanged;
        glm::mat4 m_Transform;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::TransformComponent, 0);
