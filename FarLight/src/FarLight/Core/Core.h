#pragma once

#include <memory>

#include "FarLight/Core/Defines.h"

#include "FarLight/Core/PlatformDetection.h"
#include "FarLight/Core/DebugDetection.h"
#include "FarLight/Core/AssertDetection.h"
#include "FarLight/Core/ProfileDetection.h"

#include "FarLight/Core/LoggerDefine.h"
#include "FarLight/Core/ProfileDefine.h"

#include "FarLight/Core/PredefinedMacros.h"

namespace FarLight
{
    template<typename T>
    using Scope = std::unique_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    template<typename T>
    using Ref = std::shared_ptr<T>;
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}
