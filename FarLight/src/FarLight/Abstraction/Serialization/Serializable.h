#pragma once

namespace FarLight
{
    class Serializable
    {
    public:
        virtual ~Serializable() noexcept = default;

        virtual void Serialize() const noexcept = 0;
        virtual void Deserialize() noexcept = 0;
    };
}
