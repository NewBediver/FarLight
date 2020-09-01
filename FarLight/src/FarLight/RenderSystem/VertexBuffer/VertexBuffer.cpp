// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/VertexBuffer/VertexBuffer.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

#include "Platform/Renderer/OpenGL/VertexBuffer/OpenGLVertexBuffer.h"

namespace FarLight
{
    Ref<VertexBuffer> VertexBuffer::Create(const void* vertices, unsigned size, const BufferLayout& layout) noexcept
    {
        switch (Renderer2D::GetAPI())
        {
            case RendererAPI::API::None:
            {
                FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(vertices, size, layout);
        }

        FL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<VertexBuffer> VertexBuffer::Create(unsigned size, const BufferLayout& layout) noexcept
    {
        switch (Renderer2D::GetAPI())
        {
            case RendererAPI::API::None:
            {
                FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexBuffer>(size, layout);
        }

        FL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

}
