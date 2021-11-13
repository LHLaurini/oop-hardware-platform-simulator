#include "platformdefinition.hpp"

#include <algorithm>

PlatformDefinition::PlatformDefinition() = default;

PlatformDefinition::PlatformDefinition(const Definition &definition)
    : label_(definition.fromKey("LABEL"))
    , components_([&] {
        auto [begin, end] = definition.rangeFromKey("COMPONENT");
        std::vector<std::filesystem::path> v;
        std::transform(begin, end, std::back_inserter(v), [](auto &x) { return x.second; });
        return v;
    }())
    , priority_(std::stoi(definition.fromKey("PRIORITY")))
{
}

std::string PlatformDefinition::label() const
{
    return label_;
}

std::vector<std::filesystem::path> PlatformDefinition::components() const
{
    return components_;
}

unsigned int PlatformDefinition::priority() const
{
    return priority_;
}
