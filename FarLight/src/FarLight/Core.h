#pragma once

#ifdef FL_PLATFORM_WINDOWS
	#ifdef FL_BUILD_DLL
		#define FARLIGHT_API __declspec(dllexport)
	#else
		#define FARLIGHT_API __declspec(dllimport)
	#endif
#else
	#error FarLight only support Windows!
#endif

#ifdef FL_ENABLE_ASSERTS
	#define FL_ASSERT(x, ...) {if (!(x)) {FL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define FL_CORE_ASSERT(x, ...) {if (!(x)) {FL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define FL_ASSERT(x, ...)
	#define FL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define FL_BIND_EVENT_FUNC(func) std::bind(&func, this, std::placeholders::_1)