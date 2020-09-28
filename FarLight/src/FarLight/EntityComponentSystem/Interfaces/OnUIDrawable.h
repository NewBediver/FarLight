#pragma once

#include "FarLight/SerializationSystem/Serialization.h"

namespace FarLight
{
    class OnUIDrawable
    {
        FL_REGISTER_SERIALIZABLE;

    public:
        virtual ~OnUIDrawable() noexcept = default;

        explicit OnUIDrawable() noexcept
            : m_TitleWidth(90)
        { }

        virtual void OnUserInterfaceDraw() noexcept = 0;

        int GetTitleWidth() const noexcept { return m_TitleWidth; }

    private:
        //=Serialization part======================================
        template<class Archive>
        void save(Archive& ar, const unsigned int version) const
        {
            ar & FL_SERIALIZE_NAMED("DefaultTitleColumnWidth", m_TitleWidth);;
        }

        template<class Archive>
        void load(Archive& ar, const unsigned int version)
        {
            ar & FL_SERIALIZE_NAMED("DefaultTitleColumnWidth", m_TitleWidth);
        }
        //=========================================================

        int m_TitleWidth;
    };
}

FL_REGISTER_CLASS_VERSION(FarLight::OnUIDrawable, 0);
