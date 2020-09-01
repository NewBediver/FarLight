#pragma once

#define FL_BIT(x) (1 << (x))
#define FL_BIND_EVENT_FUNC(function) [this](auto&&... args) -> decltype(auto) { return this->function(std::forward<decltype(args)>(args)...); }
