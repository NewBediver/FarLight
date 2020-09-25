#pragma once

namespace FarLight
{
    class OnUIDrawable
    {
    public:
        virtual ~OnUIDrawable() noexcept = default;

        explicit OnUIDrawable() noexcept
            : m_TitleWidth(90)
        { }


        virtual void OnUserInterfaceDraw() noexcept = 0;

        int GetTitleWidth() const noexcept { return m_TitleWidth; }

    private:
        int m_TitleWidth;
    };
}
