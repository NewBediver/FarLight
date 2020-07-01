#pragma once

#include "flpch.h"

#include "FarLight/EventSystem/Event.h"

namespace FarLight
{
	class FARLIGHT_API WindowResizedEvent
		: public Event
	{
		using uint = unsigned int;

	public:
		explicit WindowResizedEvent(uint width, uint height);

		uint GetWidth() const;
		uint GetHeight() const;

		static EventType GetStaticType();

		virtual EventType GetType() const override;
		virtual std::string GetName() const override;
		virtual int GetCategoryFlags() const override;

		virtual std::string ToString() const override;

	private:
		uint _width, _height;
	};
}