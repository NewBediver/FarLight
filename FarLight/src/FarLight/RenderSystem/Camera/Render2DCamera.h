#pragma once

#include <glm/glm.hpp>

namespace FarLight
{
	class Render2DCamera
	{
	public:
		explicit Render2DCamera(unsigned width, unsigned height, float zoom = 1.0f) noexcept;

		void SetProjection(const glm::mat4 projection) noexcept { m_Projection = projection; }
		const glm::mat4& GetProjection() const noexcept { return m_Projection; }

		void SetAspectRatio(unsigned width, unsigned height) noexcept;
		float GetAspectRatio() const noexcept { return static_cast<float>(m_Width) / static_cast<float>(m_Height); }

		void SetWidth(unsigned width) noexcept;
		unsigned GetWidth() const noexcept { return m_Width; }

		void SetHeight(unsigned height) noexcept;
		unsigned GetHeight() const noexcept { return m_Height; }

		void SetZoomLevel(float zoom) noexcept;
		float GetZoomLevel() const noexcept { return m_ZoomLevel; }

	private:
		void RecalculateProjectionMatrix() noexcept;

		glm::mat4 m_Projection;
		unsigned m_Width, m_Height;
		float m_ZoomLevel;
	};
}