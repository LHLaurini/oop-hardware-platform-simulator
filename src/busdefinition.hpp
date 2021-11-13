#pragma once

#include "definition.hpp"

#include <filesystem>
#include <map>
#include <string>

class BusDefinition
{
  public:
    BusDefinition();
    BusDefinition(const Definition &definition);

    std::string label() const;
    int width() const;
    std::string source() const;
    unsigned int priority() const;

  private:
    std::string label_;
    int width_;
    std::string source_;
    unsigned int priority_;
};
