#pragma once

#include <memory>

#include "FarLight/Core/AdditionDefine.h"

#include "FarLight/Core/PlatformDetection.h"
#include "FarLight/Core/ArchitectureDetection.h"
#include "FarLight/Core/CompilerDetection.h"

#include "FarLight/Core/BreakpointDetection.h"
#include "FarLight/Core/FunctionSignatureDetection.h"

#include "FarLight/Core/LoggerDefine.h"
#include "FarLight/Core/AssertDefine.h"
#include "FarLight/Core/ProfileDefine.h"

namespace FarLight
{
    #define FL_VERSION_MAJOR 0
    #define FL_VERSION_MINOR 0
    #define FL_VERSION_PATCH 0
    #define FL_VERSION_SUFFIX ""
    #define FL_VERSION_NAME "Fresh"

    #define FL_VERSION    ((FL_VERSION_MAJOR << 16) | (FL_VERSION_MINOR << 8) | FL_VERSION_PATCH)

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
