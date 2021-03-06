#pragma once

#include <array>

#include <glm/glm.hpp>

namespace FarLight
{
    class Texture
    {
    public:
        virtual ~Texture() noexcept = default;

        virtual void Bind(unsigned slot) const noexcept = 0;
        virtual void Unbind(unsigned slot) const noexcept = 0;

        virtual unsigned GetID() const noexcept = 0;

        virtual unsigned GetWidth() const noexcept = 0;
        virtual unsigned GetHeight() const noexcept = 0;

        virtual const std::array<glm::vec2, 4>& GetCoordinates() const noexcept = 0;
        virtual const glm::vec2& GetLowerLeftCoordinate() const noexcept = 0;
        virtual const glm::vec2& GetLowerRightCoordinate() const noexcept = 0;
        virtual const glm::vec2& GetUpperRightCoordinate() const noexcept = 0;
        virtual const glm::vec2& GetUpperLeftCoordinate() const noexcept = 0;

        virtual void SetData(const void* data, unsigned size) const noexcept = 0;
    };
}
