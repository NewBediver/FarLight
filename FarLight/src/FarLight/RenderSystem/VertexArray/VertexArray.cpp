// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

#include "Platform/Renderer/OpenGL/VertexArray/OpenGLVertexArray.h"

namespace FarLight
{
    Ref<VertexArray> VertexArray::Create() noexcept
    {
        switch (Renderer2D::GetAPI())
        {
            case RendererAPI::API::None:
            {
                FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
        }

        FL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
