#pragma once

#include <filesystem>
#include <fstream>
#include <optional>
#include <unordered_map>
#include <utility>

class Component;
class CPUDefinition;
class BusDefinition;
class MemoryDefinition;
class DisplayDefinition;
class PlatformDefinition;

class Definition
{
  public:
    Definition();
    Definition(const std::filesystem::path &path);

    enum class Type
    {
        CPU,
        BUS,
        MEMORY,
        DISPLAY,
        PLATFORM,
    };

    Type type() const;

    using Definitions = std::unordered_multimap<std::string, std::string>;
    using IteratorPair = std::pair<Definitions::const_iterator, Definitions::const_iterator>;

    // methods
    CPUDefinition makeCPUDefinition() const;
    BusDefinition makeBusDefinition() const;
    MemoryDefinition makeMemoryDefinition() const;
    DisplayDefinition makeDisplayDefinition() const;
    PlatformDefinition makePlatformDefinition() const;
    std::unique_ptr<Component> makeComponent() const;
    std::string fromKey(const std::string &key) const;
    IteratorPair rangeFromKey(const std::string &key) const;

  private:
    std::optional<std::pair<std::string, std::string>> readLine();
    static std::string trimWhitespace(const std::string &str);

    std::ifstream stream;
    Definitions definitions;
    Type type_;
};