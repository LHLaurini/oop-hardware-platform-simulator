#pragma once

#include "definition.hpp"

#include <filesystem>
#include <map>
#include <span>
#include <string>
#include <vector>

class MemoryDefinition
{
  public:
    MemoryDefinition();
    MemoryDefinition(const Definition &definition);

    std::string label() const;
    int size() const;
    int access() const;
    std::string source() const;
    unsigned int priority() const;
    std::span<const double> init() const;

  private:
    std::string label_;
    int size_;
    int access_;
    std::string source_;
    unsigned int priority_;
    std::vector<double> init_;
};
