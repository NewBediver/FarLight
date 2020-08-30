#pragma once

#ifdef FL_DEBUG
    #define FL_ENABLE_ASSERTS
    #if defined(FL_PLATFORM_WINDOWS)
        #define FL_DEBUGBREAK() __debugbreak()
    #elif defined(FL_PLATFORM_LINUX)
        #include <signal.h>
        #define FL_DEBUGBREAK() raise(SIGTRAP)
    #else
        #error "Platform doesn't support debugbreak yet!"
    #endif
#else
    #define FL_DEBUGBREAK()
#endif
