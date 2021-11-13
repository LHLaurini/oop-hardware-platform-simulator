#include "memorydefinition.hpp"

MemoryDefinition::MemoryDefinition() = default;

MemoryDefinition::MemoryDefinition(const Definition &definition)
    : label_(definition.fromKey("LABEL"))
    , size_(std::stoi(definition.fromKey("SIZE")))
    , access_(std::stoi(definition.fromKey("ACCESS")))
    , source_(definition.fromKey("SOURCE"))
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
