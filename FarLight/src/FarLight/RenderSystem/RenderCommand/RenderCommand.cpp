// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include "Platform/Renderer/OpenGL/RendererAPI/OpenGLRendererAPI.h"

namespace FarLight
{
    const Scope<RendererAPI>& RenderCommand::GetInstance() noexcept
    {
        #ifdef FL_PLATFORM_WINDOWS
            static Scope<RendererAPI> s_Instance = CreateScope<OpenGLRendererAPI>();
            return s_Instance;
        #else
            FL_CORE_ASSERT(false, "Unknown platform!");
            static Scope<RendererAPI> s_Instance = nullptr;
            return s_Instance;
        #endif
    }

    void RenderCommand::Init() noexcept
    {
        FL_PROFILE_FUNCTION();

        GetInstance()->Init();
    }

    void RenderCommand::SetClearColor(const glm::vec4& color) noexcept
    {
        FL_PROFILE_FUNCTION();

        GetInstance()->SetClearColor(color);
    }

    void RenderCommand::SetViewport(unsigned x, unsigned y, unsigned width, unsigned height) noexcept
    {
        FL_PROFILE_FUNCTION();

        GetInstance()->SetViewport(x, y, width, height);
    }

    void RenderCommand::DrawIndexed(const Ref<VertexArray>& vertexArray) noexcept
    {
        FL_PROFILE_FUNCTION();

        GetInstance()->DrawIndexed(vertexArray);
    }

    void RenderCommand::Clear() noexcept
    {
        FL_PROFILE_FUNCTION();

        GetInstance()->Clear();
    }
}
