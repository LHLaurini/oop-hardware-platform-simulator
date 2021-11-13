#pragma once

#include "definition.hpp"

#include <filesystem>
#include <string>
#include <vector>

class PlatformDefinition
{
  public:
    PlatformDefinition();
    PlatformDefinition(const Definition &definition);

    std::string label() const;
    std::vector<std::filesystem::path> components() const;
    unsigned int priority() const;

  private:
    std::string label_;
    std::vector<std::filesystem::path> components_;
    unsigned int priority_;
};
