#include "flpch.h"

#include "IndexBuffer.h"

#include "FarLight/RenderSystem/Renderer.h"
#include "FarLight/Platform/Renderer/OpenGL/IndexBuffer/OpenGLIndexBuffer.h"

namespace FarLight
{
	std::unique_ptr<IndexBuffer> IndexBuffer::Create(unsigned int* indicies, unsigned int count)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::OpenGL:  return std::make_unique<OpenGLIndexBuffer>(indicies, count);
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}


