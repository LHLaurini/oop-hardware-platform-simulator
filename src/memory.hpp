#pragma once

#include "component.hpp"

#include <ctime>
#include <iostream>
#include <memory>
#include <string>

class Memory : public Component
{
  public:
    Memory();
    Memory(std::istream &definition);

    // getters
    std::string label() const;
    unsigned int size() const;
    std::time_t accessTime() const;
    // Source source() const;

    // methods
    void simulate();
    DataValue read();

  private:
    unsigned int size_;
    std::time_t accessTime_;
    std::string label_;
    std::unique_ptr<double[]> data;
};