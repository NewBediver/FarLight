#pragma once

#include <glm/glm.hpp>

namespace FarLight
{
	class RenderCamera
	{
	public:
		explicit RenderCamera(const glm::mat4& projection) noexcept
			: m_Projection(projection)
		{ }

		void SetProjection(const glm::mat4 projection) noexcept { m_Projection = projection; }
		const glm::mat4& GetProjection() const noexcept { return m_Projection; }

	private:
		glm::mat4 m_Projection;
	};
}