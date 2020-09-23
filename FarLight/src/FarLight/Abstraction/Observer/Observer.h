#pragma once

namespace FarLight
{
    template<typename T>
    class Observer
    {
    public:
        virtual ~Observer() noexcept = default;

        virtual void Update(const T& notification) noexcept = 0;
    };
}
