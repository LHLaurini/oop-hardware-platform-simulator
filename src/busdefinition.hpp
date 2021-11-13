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

  private:
    std::string label_;
    int width_;
    std::string source_;
};
