#pragma once

#include <filesystem>
#include <map>
#include <string>

class BusDefinition
{
  public:
    BusDefinition();
    BusDefinition(const std::map<std::string, std::string> &definition);

    std::string label() const;
    int width() const;
    std::string source() const;

  private:
    std::string label_;
    int width_;
    std::string source_;
};
