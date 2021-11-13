#include "cpudefinition.hpp"

CPUDefinition::CPUDefinition() = default;

CPUDefinition::CPUDefinition(const std::map<std::string, std::string> &definition)
    : label_(definition.at("LABEL"))
    , cores_(std::stoi(definition.at("CORES")))
    , frequency_(std::stoi(definition.at("FREQUENCY")))
    , program_(definition.at("PROGRAM"))
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
