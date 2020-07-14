#pragma once

#include "RendererAPI/RendererAPI.h"

namespace FarLight
{
	class FARLIGHT_API Renderer
	{
	public:

		static void BeginScene();
		static void EndScene();

		static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};
}