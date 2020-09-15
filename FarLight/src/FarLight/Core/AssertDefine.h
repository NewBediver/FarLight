#pragma once

#ifdef FL_ENABLE_ASSERTS
#   define FL_ASSERT(CONDITION, ...) {if (!(CONDITION)) {FL_ERROR("Assertion Failed: {0}", __VA_ARGS__); FL_DEBUGBREAK();}}
#   define FL_CORE_ASSERT(CONDITION, ...) {if (!(CONDITION)) {FL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); FL_DEBUGBREAK();}}
#else
#   define FL_ASSERT(CONDITION, ...)
#   define FL_CORE_ASSERT(CONDITION, ...)
#endif
