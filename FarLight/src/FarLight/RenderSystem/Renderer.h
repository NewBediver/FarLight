#pragma once

#include "RendererAPI/RendererAPI.h"

#include "FarLight/RenderSystem/Camera/Camera.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class FARLIGHT_API Renderer
	{
	public:
		static void BeginScene(const Camera& camera);
		static void EndScene();

		static void Init();

		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transformation = glm::mat4(1.0f));

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		Renderer() = delete;
		Renderer(const Renderer&) = delete;
		Renderer(Renderer&&) = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&&) = delete;

		struct SceneData
		{
			glm::mat4 ViewMatrix;
			glm::mat4 ProjectionMatrix;
		};

		static Scope<SceneData> _sceneData;
	};
}