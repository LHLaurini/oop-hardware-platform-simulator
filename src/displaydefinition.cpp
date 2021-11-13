#include "displaydefinition.hpp"

DisplayDefinition::DisplayDefinition() = default;

DisplayDefinition::DisplayDefinition(const Definition &definition)
    : refresh_(std::stoi(definition.fromKey("REFRESH")))
    , source_(definition.fromKey("SOURCE"))
{
}

int DisplayDefinition::refresh() const
{
    return refresh_;
}

std::string DisplayDefinition::source() const
{
    return source_;
}
