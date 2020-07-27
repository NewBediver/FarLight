#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class FARLIGHT_API RenderCommand
	{
	public:
		static void Init() { _rendererAPI->Init(); }
		static void SetClearColor(const glm::vec4& color) { _rendererAPI->SetClearColor(color); }
		static void SetViewport(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height) { _rendererAPI->SetViewport(x, y, width, height); }
		static void DrawIndexed(const Ref<VertexArray>& vertexArray) { _rendererAPI->DrawIndexed(vertexArray); }
		static void Clear() { _rendererAPI->Clear(); }

	private:
		RenderCommand() = delete;
		RenderCommand(const RenderCommand&) = delete;
		RenderCommand(RenderCommand&&) = delete;
		RenderCommand& operator=(const RenderCommand&) = delete;
		RenderCommand& operator=(RenderCommand&&) = delete;

		static Scope<RendererAPI> _rendererAPI;
	};
}