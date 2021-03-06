#pragma once

#include "FarLight/EventSystem/Event.h"

#include "FarLight/BasicFunctionality/Timer/Timestep.h"

namespace FarLight
{
    class Layer
    {
    public:
        explicit Layer(std::string&& name = "Layer") noexcept
            : m_Name(std::move(name))
        {
            FL_CORE_INFO("Layer [{0}] created.", this->GetName());
        }

        virtual ~Layer() noexcept
        {
            FL_CORE_INFO("Layer [{0}] destroyed.", this->GetName());
        }

        virtual void OnAttach() noexcept = 0;
        virtual void OnDetach() noexcept = 0;
        virtual void OnUpdate(const Timestep& timestamp) noexcept = 0;
        virtual void OnUserInterfaceRender() noexcept = 0;
        virtual void OnEvent(Event& event) noexcept = 0;

        constexpr const std::string& GetName() const noexcept { return m_Name; }

    private:
        std::string m_Name;
    };
}
