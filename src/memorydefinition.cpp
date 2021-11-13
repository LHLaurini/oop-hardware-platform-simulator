#include "memorydefinition.hpp"

#include <sstream>

MemoryDefinition::MemoryDefinition() = default;

MemoryDefinition::MemoryDefinition(const Definition &definition)
    : label_(definition.fromKey("LABEL"))
    , size_(std::stoi(definition.fromKey("SIZE")))
    , access_(std::stoi(definition.fromKey("ACCESS")))
    , source_(definition.fromKey("SOURCE"))
    , priority_(std::stoi(definition.fromKey("PRIORITY")))
    , init_([&] {
        std::vector<double> values;

        std::istringstream stream(definition.fromKey("INIT"));

        for (double value; stream >> value;)
        {
            values.emplace_back(value);
        }

        if (stream.fail() && !stream.eof())
        {
            throw std::runtime_error("extra characters in INIT");
        }

        return values;
    }())
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

unsigned int MemoryDefinition::priority() const
{
    return priority_;
}

std::span<const double> MemoryDefinition::init() const
{
    return std::span(init_);
}
