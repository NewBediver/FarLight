#pragma once

#include <string>

#include "FarLight/EntityComponentSystem/Interfaces/OnUIDrawable.h"

namespace FarLight
{
    class TagComponent final
        : public OnUIDrawable
    {
    public:
        explicit TagComponent(const std::string& tag = "Entity") noexcept
            : m_Tag(tag)
        { }

        void SetTag(const std::string& tag) noexcept { m_Tag = tag; }
        const std::string& GetTag() const noexcept { return m_Tag; }

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        std::string m_Tag;
    };
}
