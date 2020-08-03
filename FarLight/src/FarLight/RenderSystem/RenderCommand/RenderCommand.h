#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class RenderCommand
	{
	public:
		RenderCommand() = delete;
		RenderCommand(const RenderCommand&) = delete;
		RenderCommand(RenderCommand&&) = delete;
		RenderCommand& operator=(const RenderCommand&) = delete;
		RenderCommand& operator=(RenderCommand&&) = delete;

		static void Init();
		static void SetClearColor(const glm::vec4& color);
		static void SetViewport(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height);
		static void DrawIndexed(const Ref<VertexArray>& vertexArray);
		static void Clear();

	private:
		static Scope<RendererAPI> s_RendererAPI;
	};
}