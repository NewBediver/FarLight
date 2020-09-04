#pragma once

#include "FarLight/EntityComponentSystem/Interfaces/IComponent.h"

#include <glm/glm.hpp>

namespace FarLight
{
    class CameraComponent final
        : public IComponent
    {
    public:
        explicit CameraComponent(unsigned width = 1920, unsigned height = 1080, float zoom = 1.0f, bool isPrimary = true, bool isFixedAspectRatio = false) noexcept;

        bool IsFixedAspectRatio() const noexcept { return m_IsFixedAspectRatio; }
        bool IsPrimary() const noexcept { return m_IsPrimary; }

        void SetZoom(float zoom) noexcept;
        float GetZoom() const noexcept { return m_Zoom; }

        void SetAspectRatio(unsigned width, unsigned height) noexcept;

        void SetLeftBound(float left) noexcept;
        float GetLeftBound() const noexcept { return m_Left; }

        void SetRightBound(float right) noexcept;
        float GetRightBound() const noexcept { return m_Right; }

        void SetTopBound(float top) noexcept;
        float GetTopBound() const noexcept { return m_Top; }

        void SetBottomBound(float bottom) noexcept;
        float GetBottomBound() const noexcept { return m_Bottom; }

        void SetNearBound(float _near) noexcept;
        float GetNearBound() const noexcept { return m_Near; }

        void SetFarBound(float _far) noexcept;
        float GetFarBound() const noexcept { return m_Far; }

        const glm::vec3& GetUpDirection() const noexcept { return m_CameraUp; }
        const glm::vec3& GetFrontDirection() const noexcept { return m_CameraFront; }
        const glm::vec3& GetRightDirecton() const noexcept { return m_CameraRight; }

        void SetProjectionMatrix(float left, float right, float bottom, float top, float near, float far) noexcept;
        const glm::mat4& GetProjectionMatrix() noexcept;

        const glm::mat4& GetViewMatrix(const glm::vec3& position, const glm::vec3& rotation) noexcept;

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        void RecalculateViewMatrix(const glm::vec3& position) noexcept;
        void RecalculateProjectionMatrix() noexcept;

        bool m_IsPrimary, m_IsFixedAspectRatio;

        float m_AspectRatio;
        float m_Zoom;

        float m_Left, m_Right, m_Bottom, m_Top, m_Near, m_Far;

        glm::vec3 m_CameraUp;
        glm::vec3 m_CameraRight;
        glm::vec3 m_CameraFront;

        bool m_IsProjectionChanged;
        glm::mat4 m_ProjectionMatrix;
        glm::mat4 m_ViewMatrix;
    };
}
