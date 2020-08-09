// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Shader.h"

#include "FarLight/RenderSystem/Renderer/Renderer2D.h"
#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

namespace FarLight
{
	Ref<Shader> Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc) noexcept
	{
		switch (Renderer2D::GetAPI())
		{
			case RendererAPI::API::None:    FL_CORE_ASSERT(false, "RendererAPI::None is not supported!");
			case RendererAPI::API::OpenGL:  return CreateRef<OpenGLShader>(vertexSrc, fragmentSrc);
		}

		FL_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}