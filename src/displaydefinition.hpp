#pragma once

#include <filesystem>
#include <map>
#include <string>

class DisplayDefinition
{
  public:
    DisplayDefinition();
    DisplayDefinition(const std::map<std::string, std::string> &definition);

    int refresh() const;
    std::string source() const;

  private:
    int refresh_;
    std::string source_;
};
