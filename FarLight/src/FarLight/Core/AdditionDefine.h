#pragma once

// Enable profiling
#define FL_PROFILE 0
// Enable logging
#define FL_LOG 1

#define FL_BIT(X) (1 << (X))
#define FL_BIND_EVENT_FUNC(FUNCTION) [this](auto&&... args) -> decltype(auto) { return this->FUNCTION(std::forward<decltype(args)>(args)...); }
