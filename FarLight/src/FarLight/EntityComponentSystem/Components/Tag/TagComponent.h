#pragma once

#include <string>

#include "FarLight/EntityComponentSystem/Interfaces/IComponent.h"

namespace FarLight
{
    class TagComponent final
        : public IComponent
    {
    public:
        std::string Tag;

        explicit TagComponent(const std::string& tag = "Entity") noexcept;

        virtual void OnUserInterfaceDraw() noexcept override;
    };
}
