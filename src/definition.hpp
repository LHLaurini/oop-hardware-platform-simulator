#pragma once

#include <filesystem>
#include <fstream>
#include <map>
#include <optional>
#include <utility>

class Component;
class CPUDefinition;
class BusDefinition;
class MemoryDefinition;
class DisplayDefinition;

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
    };

    Type type() const;

    // methods
    CPUDefinition makeCPUDefinition() const;
    BusDefinition makeBusDefinition() const;
    MemoryDefinition makeMemoryDefinition() const;
    DisplayDefinition makeDisplayDefinition() const;
    std::unique_ptr<Component> makeComponent() const;

  private:
    std::optional<std::pair<std::string, std::string>> readLine();
    static std::string trimWhitespace(const std::string &str);

    std::ifstream stream;
    std::map<std::string, std::string> definitions;
    Type type_;
};