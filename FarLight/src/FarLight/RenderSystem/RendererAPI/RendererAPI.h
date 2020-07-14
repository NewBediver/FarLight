#pragma once

#include "FarLight/RenderSystem/VertexArray/VertexArray.h"

#include <glm/glm.hpp>

namespace FarLight
{
	class FARLIGHT_API RendererAPI
	{
	public:
		virtual ~RendererAPI() = default;

		enum class API
		{
			None = 0,
			OpenGL = 1
		};

		virtual void SetClearColor(const glm::vec4& color) const = 0;
		virtual void Clear() const = 0;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) const = 0;

		static API GetAPI() { return _api; }

	private:
		static API _api;
	};
}