#pragma once

#include "Texture.h"

#include "FarLight/Core/Core.h"

#include <string>

namespace FARLIGHT_API FarLight
{
	class Texture2D
		: public Texture
	{
	public:
		virtual ~Texture2D() = default;

		static Ref<Texture2D> Create(const std::string& path);
	};
}