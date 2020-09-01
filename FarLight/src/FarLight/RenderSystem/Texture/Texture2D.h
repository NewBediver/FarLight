#pragma once

#include <string>

#include "FarLight/RenderSystem/Texture/Texture.h"

#include <glm/glm.hpp>

namespace  FarLight
{
    class Texture2D
        : public Texture
    {
    public:
        static Ref<Texture2D> Create(const std::string& path) noexcept;
        static Ref<Texture2D> Create(unsigned width, unsigned height, const glm::vec4& pixelColor = glm::vec4(1.0f)) noexcept;

        virtual ~Texture2D() noexcept = default;
    };
}
