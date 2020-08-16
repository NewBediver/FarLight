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
		void EnableDocking() const noexcept;
		void UpdateMenuBar() const noexcept;
		void UpdateRenderViewport() noexcept;

		void GetBatchingStatistic() const noexcept;


		OrthographicCameraController m_CameraController;

		Ref<Texture2D> m_Texture;
		Ref<Texture2D> m_ShovelKnightTexture;

		float m_Rotation;
		Ref<Framebuffer> m_Framebuffer;
	};
}