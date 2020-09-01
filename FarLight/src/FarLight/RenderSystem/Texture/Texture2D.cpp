// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/RenderSystem/Texture/Texture2D.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"

#include "Platform/Renderer/OpenGL/Texture/OpenGLTexture2D.h"

namespace FarLight
{
    Ref<Texture2D> Texture2D::Create(const std::string& path) noexcept
    {
        switch (Renderer2D::GetAPI())
        {
            case RendererAPI::API::None:
            {
                FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(path);
        }

        FL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }

    Ref<Texture2D> Texture2D::Create(unsigned width, unsigned height, const glm::vec4& pixelColor) noexcept
    {
        switch (Renderer2D::GetAPI())
        {
            case RendererAPI::API::None:
            {
                FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
                return nullptr;
            }
            case RendererAPI::API::OpenGL:  return CreateRef<OpenGLTexture2D>(width, height, pixelColor);
        }

        FL_CORE_ASSERT(false, "Unknown RendererAPI!");
        return nullptr;
    }
}
