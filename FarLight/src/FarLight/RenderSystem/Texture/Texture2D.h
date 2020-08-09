#pragma once

#include <string.h>

#include "Texture.h"

#include "FarLight/Core/Core.h"

#include <glm/glm.hpp>

namespace  FarLight
{
	class Texture2D
		: public Texture
	{
	public:
		static Ref<Texture2D> Create(const std::string& path) noexcept;
		static Ref<Texture2D> Create(unsigned width, unsigned height, const glm::vec4& pixelColor = glm::vec4(1.0f)) noexcept;

		Texture2D(const Texture2D&) = delete;
		Texture2D(Texture2D&&) = delete;
		Texture2D& operator=(const Texture2D&) = delete;
		Texture2D& operator=(Texture2D&&) = delete;

		explicit Texture2D() noexcept = default;

		virtual ~Texture2D() noexcept = default;
	};
}