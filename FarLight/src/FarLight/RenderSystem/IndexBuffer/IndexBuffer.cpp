#include "flpch.h"

#include "IndexBuffer.h"

#include "FarLight/RenderSystem/Renderer.h"
#include "Platform/Renderer/OpenGL/IndexBuffer/OpenGLIndexBuffer.h"

namespace FarLight
{
	Ref<IndexBuffer> IndexBuffer::Create(const unsigned int* indicies, const unsigned int count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::API::OpenGL:  return Ref<OpenGLIndexBuffer>(new OpenGLIndexBuffer(indicies, count));
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}