#include "flpch.h"
#include "VertexBuffer.h"

#include "FarLight/RenderSystem/Renderer.h"
#include "FarLight/Platform/Renderer/OpenGL/VertexBuffer/OpenGLVertexBuffer.h"

namespace FarLight
{
	std::unique_ptr<VertexBuffer> VertexBuffer::Create(float* verticies, unsigned int size)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::OpenGL:  return std::make_unique<OpenGLVertexBuffer>(verticies, size);
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}