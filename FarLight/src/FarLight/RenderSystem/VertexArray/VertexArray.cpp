#include "flpch.h"

#include "VertexArray.h"

#include "FarLight/RenderSystem/Renderer.h"
#include "FarLight/Platform/Renderer/OpenGL/VertexArray/OpenGLVertexArray.h"

namespace FarLight
{
	std::unique_ptr<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::OpenGL:  return std::make_unique<OpenGLVertexArray>();
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}