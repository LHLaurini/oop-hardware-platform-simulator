#pragma once

#include "definition.hpp"

#include <filesystem>
#include <map>
#include <string>

class DisplayDefinition
{
  public:
    DisplayDefinition();
    DisplayDefinition(const Definition &definition);

    int refresh() const;
    std::string source() const;
    unsigned int priority() const;

  private:
    int refresh_;
    std::string source_;
    unsigned int priority_;
};
