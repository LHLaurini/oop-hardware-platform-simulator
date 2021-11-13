#pragma once

#include "component.hpp"

#include <filesystem>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Source;

class Platform
{
  public:
    Platform();
    Platform(const std::filesystem::path &path);

    // methods
    void simulate();

  private:
    std::vector<std::unique_ptr<Component>> components;
    std::unordered_map<std::string, Source *> labelMap;
};