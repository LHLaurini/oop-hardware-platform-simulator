#pragma once

#include "definition.hpp"

#include <filesystem>
#include <map>
#include <string>

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

  private:
    std::string label_;
    int size_;
    int access_;
    std::string source_;
    unsigned int priority_;
};
