#include "flpch.h"

#include "VertexBuffer.h"

#include "FarLight/RenderSystem/Renderer.h"
#include "Platform/Renderer/OpenGL/VertexBuffer/OpenGLVertexBuffer.h"

namespace FarLight
{
	Ref<VertexBuffer> VertexBuffer::Create(const float* verticies, const unsigned int size, const BufferLayout& layout)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::API::OpenGL:  return Ref<OpenGLVertexBuffer>(new  OpenGLVertexBuffer(verticies, size, layout));
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}