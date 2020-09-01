#pragma once

#define STB_IMAGE_IMPLEMENTATION

#include "FarLight/Core/Core.h"
#include "FarLight/Core/Defines.h"
#include "FarLight/LogSystem/Logger.h"
#include "FarLight/Profiling/Instrumentor.h"

#include <iostream>
#include <ostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <iomanip>

#include <codecvt>

#include <filesystem>

#include <chrono>
#include <thread>

#include <memory>
#include <functional>
#include <utility>
#include <algorithm>
#include <numeric>

#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

#ifdef FL_PLATFORM_WINDOWS
	#include <Windows.h>

    #ifndef NOMINMAX
        // See github.com/skypjack/entt/wiki/Frequently-Asked-Questions#warning-c4003-the-min-the-max-and-the-macro
        #define NOMINMAX
    #endif
#endif
