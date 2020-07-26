// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "Renderer.h"
#include "FarLight/RenderSystem/RenderCommand/RenderCommand.h"

#include "Platform/Renderer/OpenGL/Shader/OpenGLShader.h"

namespace FarLight
{
	Scope<Renderer::SceneData> Renderer::_sceneData = std::make_unique<Renderer::SceneData>();
	
	void Renderer::BeginScene(const Camera& camera)
	{
		_sceneData->ViewMatrix = camera.GetViewMatrix();
		_sceneData->ProjectionMatrix = camera.GetProjectionMatrix();
	}

	void Renderer::EndScene() { }

	void Renderer::Init()
	{
		RenderCommand::Init();
	}

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