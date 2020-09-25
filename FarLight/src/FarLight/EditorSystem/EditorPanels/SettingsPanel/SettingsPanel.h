#pragma once

#include <FarLight.h>

#include "FarLight/EditorSystem/EditorPanels/Abstraction/Panel.h"

namespace FarLight
{
    class SettingsPanel final
        : public Panel
    {
    public:
        explicit SettingsPanel(bool show = false, const std::string& title = "Settings") noexcept
            : m_Title(title)
            , m_IsShown(show)
        {
            m_ShownFunction = &SettingsPanel::ShowApplicationSettings;
        }

        virtual void ShowContent() noexcept override;

        virtual bool IsShown() const noexcept override { return m_IsShown; }
        virtual void SetShown(bool show) noexcept override { m_IsShown = show; }

        virtual const std::string& GetTitle() const noexcept override { return m_Title; }
        virtual void SetTitle(const std::string& title) noexcept override { m_Title = title; }

    private:
        void ShowApplicationSettings() noexcept;
        void ShowDirectoriesSettings() noexcept;

        bool m_IsShown;
        std::string m_Title;
        void (SettingsPanel::*m_ShownFunction)(void) noexcept;
    };
}
