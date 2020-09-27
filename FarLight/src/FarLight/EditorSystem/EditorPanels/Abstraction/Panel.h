#pragma once

#include <string>

namespace FarLight
{
    class Panel
    {
    public:
        explicit Panel(std::string&& title)
            : m_Title(std::move(title))
        { }

        virtual ~Panel() = default;

        virtual void ShowContent() noexcept = 0;

        const std::string& GetTitle() const noexcept { return m_Title; }

    private:
        std::string m_Title;
    };
}
