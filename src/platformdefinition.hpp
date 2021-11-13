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

  private:
    std::string label_;
    std::vector<std::filesystem::path> components_;
};
