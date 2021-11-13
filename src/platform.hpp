#pragma once

#include "component.hpp"
#include "platformdefinition.hpp"

#include <filesystem>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

class Source;

class Platform : public Component
{
  public:
    Platform();
    Platform(const PlatformDefinition &path);

    std::string label() const;

    // methods
    void simulate() override;

  private:
    std::string label_;
    std::vector<std::unique_ptr<Component>> components;
    std::unordered_map<std::string, Source *> labelMap;
};