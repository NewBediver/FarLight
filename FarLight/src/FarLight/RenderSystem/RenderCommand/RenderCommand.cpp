// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "RenderCommand.h"

#include "Platform/Renderer/OpenGL/RendererAPI/OpenGLRendererAPI.h"

namespace FarLight
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = CreateScope<OpenGLRendererAPI>();

	void RenderCommand::Init()
	{
		FL_PROFILE_FUNCTION();

		s_RendererAPI->Init();
	}

	void RenderCommand::SetClearColor(const glm::vec4& color)
	{
		FL_PROFILE_FUNCTION();

		s_RendererAPI->SetClearColor(color);
	}

	void RenderCommand::SetViewport(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height)
	{
		FL_PROFILE_FUNCTION();

		s_RendererAPI->SetViewport(x, y, width, height);
	}

	void RenderCommand::DrawIndexed(const Ref<VertexArray>& vertexArray)
	{
		FL_PROFILE_FUNCTION();

		s_RendererAPI->DrawIndexed(vertexArray);
	}
	
	void RenderCommand::Clear()
	{
		FL_PROFILE_FUNCTION();

		s_RendererAPI->Clear();
	}
}