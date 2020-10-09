#pragma once

#include <memory>

#include "FarLight/Abstraction/EngineObject/EngineID.h"

namespace FarLight
{
    class EngineObject
    {
        friend class SceneSerializerConfiguration;
        friend class ComponentSerializerConfiguration;

    public:
        explicit EngineObject() noexcept = default;
        virtual ~EngineObject() noexcept = default;

        explicit EngineObject(EngineID&& id) noexcept
            : m_Id(std::move(id))
        { }

        const EngineID& GetId() const noexcept { return m_Id; }

    private:
        EngineID m_Id;
    };
}
