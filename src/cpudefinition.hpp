#pragma once

#include "definition.hpp"

#include <filesystem>
#include <map>
#include <string>

class CPUDefinition
{
  public:
    CPUDefinition();
    CPUDefinition(const Definition &definition);

    std::string label() const;
    int cores() const;
    int frequency() const;
    std::filesystem::path program() const;

  private:
    std::string label_;
    int cores_;
    int frequency_;
    std::filesystem::path program_;
};
