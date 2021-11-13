#include "busdefinition.hpp"

BusDefinition::BusDefinition() = default;

BusDefinition::BusDefinition(const Definition &definition)
    : label_(definition.fromKey("LABEL"))
    , width_(std::stoi(definition.fromKey("WIDTH")))
    , source_(definition.fromKey("SOURCE"))
    , priority_(std::stoi(definition.fromKey("PRIORITY")))
{
}

std::string BusDefinition::label() const
{
    return label_;
}

int BusDefinition::width() const
{
    return width_;
}

std::string BusDefinition::source() const
{
    return source_;
}

unsigned int BusDefinition::priority() const
{
    return priority_;
}
