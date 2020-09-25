#pragma once

namespace FarLight
{
    class Configurable
    {
    public:
        explicit Configurable() noexcept
        {
            Load();
        }

        virtual ~Configurable() noexcept
        {
            Save();
        }

        virtual void Save() const noexcept = 0;
        virtual void Load() noexcept = 0;
    };
}
