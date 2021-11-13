#pragma once

#include "component.hpp"
#include "platformdefinition.hpp"

#include <filesystem>
#include <iostream>
#include <list>
#include <memory>
#include <string>
#include <unordered_map>

class Source;

class Platform : public Component
{
  public:
    Platform();
    Platform(const PlatformDefinition &path);

    std::string label() const;
    unsigned int priority() const;

    // methods
    void simulate(bool verbose) override;

  private:
    std::string label_;
    std::list<std::unique_ptr<Component>> components;
    std::unordered_map<std::string, Source *> labelMap;
    unsigned int priority_;
};