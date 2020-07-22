#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class FARLIGHT_API RenderCommand
	{
	public:
		static void SetClearColor(const glm::vec4& color) { _rendererAPI->SetClearColor(color); }
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