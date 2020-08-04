#pragma once

#include "FarLight/Core/Core.h"

namespace FarLight
{
	class Texture
	{
	public:
		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void Bind(unsigned int slot) const = 0;
		virtual void Unbind(unsigned int slot) const = 0;

		virtual void SetData(void* data, unsigned int size) const = 0;

		virtual unsigned int GetID() const = 0;

		virtual ~Texture() = default;
	};
}