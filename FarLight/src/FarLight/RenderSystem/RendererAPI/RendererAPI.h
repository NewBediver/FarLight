#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL
		};

		virtual void Init() const = 0;
		virtual void SetClearColor(const glm::vec4& color) const = 0;
		virtual void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) const = 0;
		virtual void Clear() const = 0;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) const = 0;

		virtual ~RendererAPI() = default;

		static API GetAPI() { return s_Api; }

	private:
		static API s_Api;
	};
}