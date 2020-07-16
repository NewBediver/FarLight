#pragma once

#include "RendererAPI/RendererAPI.h"

#include "FarLight/RenderSystem/Camera/OrthographicCamera.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class FARLIGHT_API Renderer
	{
	public:
		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();

		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray);

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static std::unique_ptr<SceneData> _sceneData;
	};
}