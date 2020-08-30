#pragma once

#include "FarLight/LayerSystem/Layer.h"

namespace FarLight
{
    class LayerStack final
    {
    public:
        explicit LayerStack() noexcept
            : m_LayerInsertIndex(0)
        { }

        void PushLayer(const Ref<Layer>& layer) noexcept;
        void PushOverlay(const Ref<Layer>& overlay) noexcept;
        void PopLayer(const Ref<Layer>& layer) noexcept;
        void PopOverlay(const Ref<Layer>& overlay) noexcept;

        std::vector<Ref<Layer>>::const_iterator cbegin() const noexcept { return m_Layers.cbegin(); }
        std::vector<Ref<Layer>>::const_iterator cend() const noexcept { return m_Layers.cend(); }
        std::vector<Ref<Layer>>::const_reverse_iterator crbegin() const noexcept { return m_Layers.crbegin(); }
        std::vector<Ref<Layer>>::const_reverse_iterator crend() const noexcept { return m_Layers.crend(); }

    private:
        std::vector<Ref<Layer>> m_Layers;
        unsigned m_LayerInsertIndex;
    };
}
