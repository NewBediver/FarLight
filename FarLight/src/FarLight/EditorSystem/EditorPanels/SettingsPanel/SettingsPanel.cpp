#include "flpch.h"

#include <FarLight.h>

#include "FarLight/EditorSystem/EditorPanels/SettingsPanel/SettingsPanel.h"

#include "FarLight/VirtualFileSystem/FileSystem.h"

#include "FarLight/ConfigurationSystem/LocalConfigurations/Directories/DirectoriesConfiguration.h"
#include "FarLight/ConfigurationSystem/LocalConfigurations/Application/ApplicationConfiguration.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace FarLight
{
    void SettingsPanel::ShowContent() noexcept
    {
        if (m_IsShown)
        {
            ImGui::Begin(m_Title.c_str(), &m_IsShown);

            if (ImGui::Button("Application"))
                m_ShownFunction = &SettingsPanel::ShowApplicationSettings;

            ImGui::SameLine();

            if (ImGui::Button("Directories"))
                m_ShownFunction = &SettingsPanel::ShowDirectoriesSettings;

            (this->*m_ShownFunction)();
            
            ImGui::End();
        }
    }

    void SettingsPanel::ShowApplicationSettings() noexcept
    {
        ApplicationConfiguration config;

        {
            std::string tmp = config.GetTitle();
            if (ImGui::InputText("Assets", tmp.data(), tmp.capacity() + 1, ImGuiInputTextFlags_CallbackResize,
                [](ImGuiInputTextCallbackData* data)
                {
                    std::string* str = static_cast<std::string*>(data->UserData);
                    str->resize(data->BufTextLen);
                    data->Buf = str->data();
                    return 0;
                }, &tmp))
            {
                config.SetTitle(tmp);
            }
        }

        {
            int width = static_cast<int>(config.GetWidth());
            if (ImGui::SliderInt("Width", &width, 1, 1920))
                config.SetWidth(width);
        }

        {
            int height = static_cast<int>(config.GetHeight());
            if (ImGui::SliderInt("Height", &height, 1, 1080))
                config.SetHeight(height);
        }
    }

    void SettingsPanel::ShowDirectoriesSettings() noexcept
    {
        DirectoriesConfiguration config;

        {
            std::string tmp = config.GetSettings();
            ImGui::InputText("Settings", tmp.data(), tmp.size(), ImGuiInputTextFlags_ReadOnly);
        }

        {
            std::string tmp = config.GetAssets();
            if (ImGui::InputText("Assets", tmp.data(), tmp.capacity() + 1, ImGuiInputTextFlags_CallbackResize,
                [](ImGuiInputTextCallbackData* data)
                {
                    std::string* str = static_cast<std::string*>(data->UserData);
                    str->resize(data->BufTextLen);
                    data->Buf = str->data();
                    return 0;
                }, &tmp))
            {
                config.SetAssets(tmp);
            }
        }

        {
            std::string tmp = config.GetEditor();
            if (ImGui::InputText("Editor", tmp.data(), tmp.capacity() + 1, ImGuiInputTextFlags_CallbackResize,
                [](ImGuiInputTextCallbackData* data)
                {
                    std::string* str = static_cast<std::string*>(data->UserData);
                    str->resize(data->BufTextLen);
                    data->Buf = str->data();
                    return 0;
                }, &tmp))
            {
                config.SetEditor(tmp);
            }
        }

        {
            std::string tmp = config.GetShaders();
            if (ImGui::InputText("Shaders", tmp.data(), tmp.capacity() + 1, ImGuiInputTextFlags_CallbackResize,
                [](ImGuiInputTextCallbackData* data)
                {
                    std::string* str = static_cast<std::string*>(data->UserData);
                    str->resize(data->BufTextLen);
                    data->Buf = str->data();
                    return 0;
                }, &tmp))
            {
                config.SetShaders(tmp);
            }
        }
    }
}
