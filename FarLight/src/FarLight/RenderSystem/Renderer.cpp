#include "flpch.h"

#include "Renderer.h"
#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

namespace FarLight
{
	Scope<Renderer::SceneData> Renderer::_sceneData = Scope<Renderer::SceneData>(new Renderer::SceneData());

	void Renderer::BeginScene(const OrthographicCamera& camera)
	{
		_sceneData->ViewMatrix = camera.GetViewMatrix();
		_sceneData->ProjectionMatrix = camera.GetProjectionMatrix();
	}

	void Renderer::EndScene() { }

	void Renderer::Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transformation)
	{
		shader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Projection", _sceneData->ProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_View", _sceneData->ViewMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->UploadUniformMat4("u_Model", transformation);

		vertexArray->Bind();
		RenderCommand::DrawIndexed(vertexArray);
	}
}