// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "flpch.h"

#include "Framebuffer.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"
#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

#include "Platform/Renderer/OpenGL/Framebuffer/OpenGLFramebuffer.h"

namespace FarLight
{
	Ref<Framebuffer> FarLight::Framebuffer::Create(const FramebufferSpecification& spec) noexcept
	{
		switch (Renderer2D::GetAPI())
		{
			case RendererAPI::API::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLFramebuffer>(spec);
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}