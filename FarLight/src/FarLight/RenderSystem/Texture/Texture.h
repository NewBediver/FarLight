#pragma once

#include "FarLight/Core.h"

namespace FarLight
{
	class FARLIGHT_API Texture
	{
	public:
		virtual const unsigned int GetWidth() const = 0;
		virtual const unsigned int GetHeight() const = 0;

		virtual void Bind(const unsigned int slot) const = 0;

		virtual ~Texture() = default;
	};
}