#include "SceneHierarchyPanel.h"

#include "imgui.h"

namespace FarLight
{
	SceneHierarchyPanel::SceneHierarchyPanel(const Ref<Scene>& scene, bool show, bool editable, const std::string& title) noexcept
		: m_Scene(scene)
		, m_IsShown(show)
		, m_IsEditable(editable)
		, m_Title(title)
	{ }

	void SceneHierarchyPanel::ShowConstantContent() const noexcept
	{
		if (m_IsShown && !m_IsEditable)
		{
			ImGui::Begin(m_Title.c_str(), &m_IsShown);

			auto entities = m_Scene->GetEntities<TagComponent>();
			for (int i = 0; i < entities.size(); ++i)
			{
				ImGui::PushID(i);

				auto& tagComp = entities[i].GetComponent<TagComponent>();
				if (ImGui::TreeNode("%s", tagComp.Tag.c_str()))
				{
					tagComp.OnUserInterfaceConstantDraw();

					ShowConstantComponent<TransformComponent>(entities[i], "Transform");
					ShowConstantComponent<Camera2DComponent>(entities[i], "Camera 2D");
					ShowConstantComponent<RenderComponent>(entities[i], "Render");

					ImGui::TreePop();
				}

				ImGui::PopID();
			}
			ImGui::End();
		}
	}

	void SceneHierarchyPanel::ShowEditableContent() noexcept
	{
		if (m_IsShown && m_IsEditable)
		{
			ImGui::Begin(m_Title.c_str(), &m_IsShown);

			ShowCreateButton();

			auto entities = m_Scene->GetEntities<TagComponent>();
			for (int i = 0; i < entities.size(); ++i)
			{
				ImGui::PushID(i);

				auto& tagComp = entities[i].GetComponent<TagComponent>();
				if (ImGui::TreeNode("%s", tagComp.Tag.c_str()))
				{
					tagComp.OnUserInterfaceEditableDraw();

					ShowEditableComponent<TransformComponent>(entities[i], "Transform");
					ShowEditableComponent<Camera2DComponent>(entities[i], "Camera 2D");
					ShowEditableComponent<RenderComponent>(entities[i], "Render");

					ImGui::TreePop();
				}

				ImGui::PopID();
			}

			ImGui::End();
		}
	}

	void SceneHierarchyPanel::ShowCreateButton() noexcept
	{
		if (ImGui::Button("Create square", { ImGui::GetContentRegionAvail().x, 25 }))
		{
			auto tmp = m_Scene->CreateEntity();
			tmp.AddComponent<RenderComponent>();
		}
	}
}