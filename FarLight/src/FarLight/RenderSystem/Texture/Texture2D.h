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
		static Ref<Texture2D> Create(const std::string& path);
		static Ref<Texture2D> Create(unsigned width, unsigned height, const glm::vec4& pixelColor = glm::vec4(1.0f));

		virtual ~Texture2D() = default;
	};
}