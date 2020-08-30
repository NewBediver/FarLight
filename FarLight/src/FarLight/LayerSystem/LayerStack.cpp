// This is an open source non-commercial project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "flpch.h"

#include "FarLight/LayerSystem/LayerStack.h"

namespace FarLight
{
    void LayerStack::PushLayer(const Ref<Layer>& layer) noexcept
    {
        FL_PROFILE_FUNCTION();

        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
        ++m_LayerInsertIndex;
        layer->OnAttach();

        FL_CORE_INFO("Layer [{0}] pushed and attached.", layer->GetName());
    }

    void LayerStack::PushOverlay(const Ref<Layer>& overlay) noexcept
    {
        FL_PROFILE_FUNCTION();

        m_Layers.emplace_back(overlay);
        overlay->OnAttach();

        FL_CORE_INFO("Overlay [{0}] pushed and attached.", overlay->GetName());
    }

    void LayerStack::PopLayer(const Ref<Layer>& layer) noexcept
    {
        FL_PROFILE_FUNCTION();

        auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
        if (it != m_Layers.begin() + m_LayerInsertIndex)
        {
            (*it)->OnDetach();
            m_Layers.erase(it);
            --m_LayerInsertIndex;
            FL_CORE_INFO("Layer [{0}] detached and popped.", layer->GetName());
        }
    }

    void LayerStack::PopOverlay(const Ref<Layer>& overlay) noexcept
    {
        FL_PROFILE_FUNCTION();

        auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
        if (it != m_Layers.end())
        {
            (*it)->OnDetach();
            m_Layers.erase(it);
            FL_CORE_INFO("Overlay [{0}] detached and popped.", overlay->GetName());
        }
    }
}
