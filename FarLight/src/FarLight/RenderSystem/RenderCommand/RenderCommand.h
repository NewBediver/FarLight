#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class FARLIGHT_API RenderCommand
	{
	public:
		static void SetClearColor(const glm::vec4& color) { _rendererAPI->SetClearColor(color); }
		static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) { _rendererAPI->DrawIndexed(vertexArray); }
		static void Clear() { _rendererAPI->Clear(); }

	private:
		static std::shared_ptr<RendererAPI> _rendererAPI;
	};
}