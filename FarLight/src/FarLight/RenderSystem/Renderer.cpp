#include "flpch.h"

#include "Renderer.h"
#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

namespace FarLight
{
	std::unique_ptr<Renderer::SceneData> Renderer::_sceneData = std::make_unique<Renderer::SceneData>();

	void Renderer::BeginScene(OrthographicCamera& camera)
	{
		_sceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene() { }

	void Renderer::Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transformation)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_ViewProjection", _sceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Transformation", transformation);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}