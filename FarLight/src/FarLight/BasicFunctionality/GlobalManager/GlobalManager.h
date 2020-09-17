#pragma once

#include "FarLight/Core/Core.h"

#include "FarLight/Abstraction/Singleton/Singleton.h"

namespace FarLight
{
    class GlobalManager
        : public Singleton<GlobalManager>
    {
    public:
        void GlobalInitialization() const noexcept;
        void GlobalTermination() const noexcept;
    };
}
