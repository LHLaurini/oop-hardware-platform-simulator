#include "cpudefinition.hpp"

CPUDefinition::CPUDefinition() = default;

CPUDefinition::CPUDefinition(const Definition &definition)
    : label_(definition.fromKey("LABEL"))
    , cores_(std::stoi(definition.fromKey("CORES")))
    , frequency_(std::stoi(definition.fromKey("FREQUENCY")))
    , program_(definition.fromKey("PROGRAM"))
    , priority_(std::stoi(definition.fromKey("PRIORITY")))
{
}

std::string CPUDefinition::label() const
{
    return label_;
}

int CPUDefinition::cores() const
{
    return cores_;
}

int CPUDefinition::frequency() const
{
    return frequency_;
}

std::filesystem::path CPUDefinition::program() const
{
    return program_;
}

unsigned int CPUDefinition::priority() const
{
    return priority_;
}
