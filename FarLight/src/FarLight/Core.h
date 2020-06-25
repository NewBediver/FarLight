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

#define BIT(x) (1 << x)