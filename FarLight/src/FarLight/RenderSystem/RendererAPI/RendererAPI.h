#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class FARLIGHT_API RendererAPI
	{
	public:
		enum class API
		{
			None = 0,
			OpenGL = 1
		};

		virtual void Init() const = 0;
		virtual void SetClearColor(const glm::vec4& color) const = 0;
		virtual void SetViewport(const unsigned int x, const unsigned int y, const unsigned int width, const unsigned int height) const = 0;
		virtual void Clear() const = 0;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) const = 0;

		virtual ~RendererAPI() = default;

		static API GetAPI() { return _api; }

	private:
		static API _api;
	};
}