#include "displaydefinition.hpp"

DisplayDefinition::DisplayDefinition() = default;

DisplayDefinition::DisplayDefinition(const std::map<std::string, std::string> &definition)
    : refresh_(std::stoi(definition.at("REFRESH")))
    , source_(definition.at("SOURCE"))
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
