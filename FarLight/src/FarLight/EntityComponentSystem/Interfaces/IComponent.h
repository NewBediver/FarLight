#pragma once

namespace FarLight
{
    class IComponent
    {
    public:
        virtual ~IComponent() noexcept = default;

        virtual void OnUserInterfaceDraw() noexcept = 0;
    };
}
