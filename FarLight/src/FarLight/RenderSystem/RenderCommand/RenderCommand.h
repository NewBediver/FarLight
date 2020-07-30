#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class RenderCommand
	{
	public:
		static void Init() { s_RendererAPI->Init(); }
		static void SetClearColor(const glm::vec4& color) { s_RendererAPI->SetClearColor(color); }
		static void SetViewport(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height) { s_RendererAPI->SetViewport(x, y, width, height); }
		static void DrawIndexed(const Ref<VertexArray>& vertexArray) { s_RendererAPI->DrawIndexed(vertexArray); }
		static void Clear() { s_RendererAPI->Clear(); }

	private:
		RenderCommand() = delete;
		RenderCommand(const RenderCommand&) = delete;
		RenderCommand(RenderCommand&&) = delete;
		RenderCommand& operator=(const RenderCommand&) = delete;
		RenderCommand& operator=(RenderCommand&&) = delete;

		static Scope<RendererAPI> s_RendererAPI;
	};
}