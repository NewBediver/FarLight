#pragma once

#include "FarLight.h"

#include "EditorPanels/Interfaces/IPanel.h"

namespace FarLight
{
	class SceneHierarchyPanel final
		: public IPanel
	{
	public:
		explicit SceneHierarchyPanel(const Ref<Scene>& scene, bool show = false, bool editable = true, const std::string& title = "Scene hierarchy") noexcept;

		virtual void ShowConstantContent() const noexcept override;
		virtual void ShowEditableContent() noexcept override;

		virtual bool IsShown() const noexcept override { return m_IsShown; }
		virtual void SetShown(bool show) noexcept override { m_IsShown = show; }

		virtual bool IsEditable() const noexcept override { return m_IsEditable; }
		virtual void SetEditable(bool edit) noexcept override { m_IsEditable = edit; }

		virtual const std::string& GetTitle() const noexcept override { return m_Title; }
		virtual void SetTitle(const std::string& title) noexcept override { m_Title = title; }

		void ShowCreateButton() noexcept;

	private:
		template<typename Comp>
		void ShowEditableComponent(const Entity& entity, const std::string& title = "Component") noexcept
		{
			if (entity.HasAllComponents<Comp>())
			{
				if (ImGui::CollapsingHeader(title.c_str()))
					entity.GetComponent<Comp>().OnUserInterfaceEditableDraw();
			}
		}

		template<typename Comp>
		void ShowConstantComponent(const Entity& entity, const std::string& title = "Component") const noexcept
		{
			if (entity.HasAllComponents<Comp>())
			{
				if (ImGui::CollapsingHeader(title.c_str()))
					entity.GetComponent<Comp>().OnUserInterfaceConstantDraw();
			}
		}

		Ref<Scene> m_Scene;
		mutable bool m_IsShown, m_IsEditable;

		std::string m_Title;
	};
}