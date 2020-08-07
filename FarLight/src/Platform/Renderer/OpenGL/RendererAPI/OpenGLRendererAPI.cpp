// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "OpenGLRendererAPI.h"

#include <glad/glad.h>

namespace FarLight
{
	void OpenGLRendererAPI::Init() const
	{
		FL_PROFILE_FUNCTION();

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
	}

	void OpenGLRendererAPI::SetClearColor(const glm::vec4& color) const
	{
		FL_PROFILE_FUNCTION();

		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRendererAPI::SetViewport(unsigned x, unsigned y, unsigned width, unsigned height) const
	{
		FL_PROFILE_FUNCTION();

		glViewport(x, y, width, height);
	}

	void OpenGLRendererAPI::Clear() const
	{
		FL_PROFILE_FUNCTION();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRendererAPI::DrawIndexed(const Ref<VertexArray>& vertexArray) const
	{
		FL_PROFILE_FUNCTION();

		glDrawElements(GL_TRIANGLES, vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);
	}
}