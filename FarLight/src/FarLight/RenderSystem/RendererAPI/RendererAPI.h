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

		static API GetAPI() noexcept;

		RendererAPI(const RendererAPI&) = delete;
		RendererAPI(RendererAPI&&) = delete;
		RendererAPI& operator=(const RendererAPI&) = delete;
		RendererAPI& operator=(RendererAPI&&) = delete;

		explicit RendererAPI() noexcept = default;

		virtual ~RendererAPI() noexcept = default;

		virtual void Init() const noexcept = 0;
		virtual void SetClearColor(const glm::vec4& color) const noexcept = 0;
		virtual void SetViewport(unsigned x, unsigned y, unsigned width, unsigned height) const noexcept = 0;
		virtual void Clear() const noexcept = 0;

		virtual void DrawIndexed(const Ref<VertexArray>& vertexArray) const noexcept = 0;
	};
}