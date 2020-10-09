#pragma once

#include <string>

#include "FarLight/Abstraction/EngineObject/EngineObject.h"

#include "FarLight/EntityComponentSystem/Interfaces/OnUIDrawable.h"

namespace FarLight
{
    class TagComponent final
        : public EngineObject
        , public OnUIDrawable
    {
    public:
        explicit TagComponent(EngineID id, std::string tag = "Entity") noexcept
            : EngineObject(std::move(id))
            , m_Tag(std::move(tag))
        { }

        explicit TagComponent(std::string tag = "Entity") noexcept
            : m_Tag(std::move(tag))
        { }

        void SetTag(const std::string& tag) noexcept { m_Tag = tag; }
        const std::string& GetTag() const noexcept { return m_Tag; }

        virtual void OnUserInterfaceDraw() noexcept override;

    private:
        std::string m_Tag;
    };
}
