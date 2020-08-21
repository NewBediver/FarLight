#pragma once

#include <FarLight.h>

#include <glm/glm.hpp>

namespace FarLight
{
	class EditorLayer
		: public Layer
	{
	public:
		explicit EditorLayer() noexcept;

		virtual void OnAttach() noexcept override;
		virtual void OnDetach() noexcept override;
		virtual void OnUpdate(const Timestep& timestamp) noexcept override;
		virtual void OnUserInterfaceRender() noexcept override;
		virtual void OnEvent(Event& event) noexcept override;

	private:
		void EnableDocking() noexcept;
		void UpdateMenuBar() noexcept;
		void UpdateRenderViewport() noexcept;

		void GetBatchingStatistic() noexcept;

		struct Options
		{
			bool ShowBatchStatistics = false;
		} m_Options;

		OrthographicCameraController m_CameraController;
		bool m_IsRenderViewportFocused, m_IsRenderViewportHovered;


		Ref<Texture2D> m_Texture;
		Ref<Texture2D> m_ShovelKnightTexture;

		float m_Rotation;
		Ref<Framebuffer> m_Framebuffer;

		Ref<AtlasMap> m_AtlasMap;
		std::unordered_map<char, glm::vec2> m_AtlasCoords;
	};
}