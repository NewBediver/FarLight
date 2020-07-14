#include "flpch.h"

#include "Renderer.h"

#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

namespace FarLight
{
	void Renderer::BeginScene() { }
	void Renderer::EndScene() { }

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray)
	{
		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}