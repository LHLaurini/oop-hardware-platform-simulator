#include "memorydefinition.hpp"

MemoryDefinition::MemoryDefinition() = default;

MemoryDefinition::MemoryDefinition(const std::map<std::string, std::string> &definition)
    : label_(definition.at("LABEL"))
    , size_(std::stoi(definition.at("SIZE")))
    , access_(std::stoi(definition.at("ACCESS")))
    , source_(definition.at("SOURCE"))
{
}

std::string MemoryDefinition::label() const
{
    return label_;
}

int MemoryDefinition::size() const
{
    return size_;
}

int MemoryDefinition::access() const
{
    return access_;
}

std::string MemoryDefinition::source() const
{
    return source_;
}
