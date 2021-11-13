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

  private:
    int refresh_;
    std::string source_;
};
