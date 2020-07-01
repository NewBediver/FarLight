#include "flpch.h"
#include "Layer.h"

namespace FarLight
{
    Layer::Layer(const std::string& name)
        : _name(name) { }

    inline const std::string& Layer::GetName() const { return _name; }
}