// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "IndexBuffer.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"
#include "Platform/Renderer/OpenGL/IndexBuffer/OpenGLIndexBuffer.h"

namespace FarLight
{
	Ref<IndexBuffer> IndexBuffer::Create(const void* indicies, unsigned count)
	{
		switch (Renderer2D::GetAPI())
		{
			case RendererAPI::API::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLIndexBuffer>(indicies, count);
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	FarLight::Ref<FarLight::IndexBuffer> IndexBuffer::Create(unsigned count)
	{
		switch (Renderer2D::GetAPI())
		{
			case RendererAPI::API::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLIndexBuffer>(count);
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}