#pragma once

#include <functional>

#include "FarLight/Abstraction/Observer/Observer.h"

namespace FarLight
{
    template<typename T>
    class Observable
    {
    public:
        virtual ~Observable() noexcept = default;

        virtual void AddObserver(Observer<T>* obs) noexcept = 0;
        virtual void RemoveObserver(Observer<T>* obs) noexcept = 0;

        virtual void NotifyAll(const T& notification) noexcept = 0;
    };
}
