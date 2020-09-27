#pragma once

#include <FarLight.h>

#include "FarLight/EditorSystem/EditorPanels/Abstraction/Panel.h"

namespace FarLight
{
    class SettingsPanel final
        : public Panel
    {
    public:
        explicit SettingsPanel(std::string&& title = "Settings") noexcept
            : Panel(std::move(title))
        { }

        virtual void ShowContent() noexcept override;

    private:
        void ShowApplicationSettings() noexcept;
        void ShowDirectoriesSettings() noexcept;
    };
}
