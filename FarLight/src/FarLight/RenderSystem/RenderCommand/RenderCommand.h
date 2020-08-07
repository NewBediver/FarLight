#pragma once

#include "FarLight/RenderSystem/RendererAPI/RendererAPI.h"

namespace FarLight
{
	class RenderCommand final
	{
	public:
		static const Scope<RendererAPI>& GetInstance();

		RenderCommand() = delete;
		RenderCommand(const RenderCommand&) = delete;
		RenderCommand(RenderCommand&&) = delete;
		RenderCommand& operator=(const RenderCommand&) = delete;
		RenderCommand& operator=(RenderCommand&&) = delete;

		static void Init();
		static void SetClearColor(const glm::vec4& color);
		static void SetViewport(unsigned x, unsigned y, unsigned width, unsigned height);
		static void DrawIndexed(const Ref<VertexArray>& vertexArray);
		static void Clear();
	};
}