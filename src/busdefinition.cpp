#include "busdefinition.hpp"

BusDefinition::BusDefinition() = default;

BusDefinition::BusDefinition(const std::map<std::string, std::string> &definition)
    : label_(definition.at("LABEL"))
    , width_(std::stoi(definition.at("WIDTH")))
    , source_(definition.at("SOURCE"))
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
