#pragma once

#include "FarLight/EventSystem/Event.h"
#include "FarLight/Core/Timestep.h"

namespace FarLight
{
	class Layer
	{
	public:
		explicit Layer(const std::string& name = "Layer")
			: m_Name(name)
		{ }

		virtual void OnAttach() = 0;
		virtual void OnDetach() = 0;
		virtual void OnUpdate(const Timestep& timestamp) = 0;
		virtual void OnUserInterfaceRender() = 0;
		virtual void OnEvent(Event& event) = 0;

		const std::string& GetName() const { return m_Name; }

		virtual ~Layer() = default;

	private:
		std::string m_Name;
	};
}
