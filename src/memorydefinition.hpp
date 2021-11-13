#pragma once

#include <filesystem>
#include <map>
#include <string>

class MemoryDefinition
{
  public:
    MemoryDefinition();
    MemoryDefinition(const std::map<std::string, std::string> &definition);

    std::string label() const;
    int size() const;
    int access() const;
    std::string source() const;

  private:
    std::string label_;
    int size_;
    int access_;
    std::string source_;
};
