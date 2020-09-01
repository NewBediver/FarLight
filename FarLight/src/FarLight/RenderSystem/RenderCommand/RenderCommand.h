#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
    class RenderCommand final
    {
    public:
        static const Scope<RendererAPI>& GetInstance() noexcept;

        RenderCommand() = delete;
        RenderCommand(const RenderCommand&) = delete;
        RenderCommand(RenderCommand&&) = delete;
        RenderCommand& operator=(const RenderCommand&) = delete;
        RenderCommand& operator=(RenderCommand&&) = delete;

        static void Init() noexcept;
        static void SetClearColor(const glm::vec4& color) noexcept;
        static void SetViewport(unsigned x, unsigned y, unsigned width, unsigned height) noexcept;
        static void DrawIndexed(const Ref<VertexArray>& vertexArray) noexcept;
        static void Clear() noexcept;
    };
}
