#include "definition.hpp"

#include "bus.hpp"
#include "busdefinition.hpp"
#include "component.hpp"
#include "cpu.hpp"
#include "cpudefinition.hpp"
#include "display.hpp"
#include "displaydefinition.hpp"
#include "memory.hpp"
#include "memorydefinition.hpp"

#include <algorithm>
#include <ranges>

Definition::Definition() = default;

Definition::Definition(const std::filesystem::path &path) : stream(path)
{
    if (!stream)
    {
        throw std::runtime_error("failed to open file " + path.string());
    }

    while (auto line = readLine())
    {
        const auto &[keyword, value] = *line;
        definitions[keyword] = value;
    }

    stream.close();

    if (!definitions.contains("TYPE"))
    {
        throw std::runtime_error("definition file must contain TYPE");
    }

    const auto &type = definitions.at("TYPE");

    if (type == "CPU")
    {
        type_ = Type::CPU;
    }
    else if (type == "BUS")
    {
        type_ = Type::BUS;
    }
    else if (type == "MEMORY")
    {
        type_ = Type::MEMORY;
    }
    else if (type == "DISPLAY")
    {
        type_ = Type::DISPLAY;
    }
    else
    {
        throw std::runtime_error("unknown component type: " + type);
    }

    definitions.erase("TYPE");
}

Definition::Type Definition::type() const
{
    return type_;
}

CPUDefinition Definition::makeCPUDefinition() const
{
    if (type() != Type::CPU)
    {
        throw std::runtime_error("mismatched type");
    }

    return CPUDefinition(definitions);
}

BusDefinition Definition::makeBusDefinition() const
{
    if (type() != Type::BUS)
    {
        throw std::runtime_error("mismatched type");
    }

    return BusDefinition(definitions);
}

MemoryDefinition Definition::makeMemoryDefinition() const
{
    if (type() != Type::MEMORY)
    {
        throw std::runtime_error("mismatched type");
    }

    return MemoryDefinition(definitions);
}

DisplayDefinition Definition::makeDisplayDefinition() const
{
    if (type() != Type::DISPLAY)
    {
        throw std::runtime_error("mismatched type");
    }

    return DisplayDefinition(definitions);
}

std::unique_ptr<Component> Definition::makeComponent() const
{
    switch (type())
    {
    case Definition::Type::CPU:
        return std::make_unique<CPU>(makeCPUDefinition());

    case Definition::Type::BUS:
        return std::make_unique<Bus>(makeBusDefinition());

    case Definition::Type::MEMORY:
        return std::make_unique<Memory>(makeMemoryDefinition());

    case Definition::Type::DISPLAY:
        return std::make_unique<Display>(makeDisplayDefinition());

    default:
        abort();
    }
}

std::optional<std::pair<std::string, std::string>> Definition::readLine()
{
    std::string line;
    if (!std::getline(stream, line))
    {
        return std::nullopt;
    }

    auto commaPos = line.find(':');

    auto keyword = trimWhitespace(line.substr(0, commaPos));
    auto value = trimWhitespace(line.substr(commaPos + 1));

    return {{keyword, value}};
}

std::string Definition::trimWhitespace(const std::string &str)
{
    auto isSpace = [](char c) { return std::isspace(c); };

    // Find first non-whitespace character
    auto a = std::ranges::find_if_not(str, isSpace) - str.begin();

    // Find last non-whitespace character
    auto revB = std::ranges::find_if_not(str | std::views::reverse, isSpace) - str.rbegin();
    auto b = str.size() - revB;

    return str.substr(a, b - a);
}