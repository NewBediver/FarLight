#pragma once

#include <string>

namespace FarLight
{
	class IPanel
	{
	public:
		virtual ~IPanel() = default;

		virtual void ShowConstantContent() const noexcept = 0;
		virtual void ShowEditableContent() noexcept = 0;

		virtual bool IsShown() const noexcept = 0;
		virtual void SetShown(bool show) noexcept = 0;

		virtual bool IsEditable() const noexcept = 0;
		virtual void SetEditable(bool edit) noexcept = 0;

		virtual const std::string& GetTitle() const noexcept = 0;
		virtual void SetTitle(const std::string& title) noexcept = 0;
	};
}