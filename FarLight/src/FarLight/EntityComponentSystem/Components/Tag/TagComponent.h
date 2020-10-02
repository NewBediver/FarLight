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
        explicit TagComponent(boost::uuids::uuid id, const std::string& tag = "Entity") noexcept
            : EngineObject(std::move(id))
            , m_Tag(tag)
        { }

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
