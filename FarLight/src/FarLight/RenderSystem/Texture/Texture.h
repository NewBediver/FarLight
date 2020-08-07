#pragma once

#include "FarLight/Core/Core.h"

namespace FarLight
{
	class Texture
	{
	public:
		virtual ~Texture() = default;

		virtual void Bind(unsigned slot) const = 0;
		virtual void Unbind(unsigned slot) const = 0;

		virtual unsigned GetID() const = 0;

		virtual unsigned GetWidth() const = 0;
		virtual unsigned GetHeight() const = 0;

		virtual void SetData(const void* data, unsigned size) const = 0;
	};
}