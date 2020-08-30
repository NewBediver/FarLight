#pragma once

#ifdef FL_ENABLE_ASSERTS
    #define FL_ASSERT(x, ...) {if (!(x)) {FL_ERROR("Assertion Failed: {0}", __VA_ARGS__); FL_DEBUGBREAK();}}
    #define FL_CORE_ASSERT(x, ...) {if (!(x)) {FL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); FL_DEBUGBREAK();}}
#else
    #define FL_ASSERT(x, ...)
    #define FL_CORE_ASSERT(x, ...)
#endif
