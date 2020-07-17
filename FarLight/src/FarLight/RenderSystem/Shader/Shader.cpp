#include "flpch.h"

#include "Shader.h"

#include "FarLight/RenderSystem/Renderer.h"
#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

namespace FarLight
{
	std::unique_ptr<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::GetAPI())
		{
			case RendererAPI::API::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::API::OpenGL:  return std::make_unique<OpenGLShader>(vertexSrc, fragmentSrc);
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}