#pragma once

#include <filesystem>
#include <map>
#include <string>

class CPUDefinition
{
  public:
    CPUDefinition();
    CPUDefinition(const std::map<std::string, std::string> &definition);

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
