#pragma once

#include "component.hpp"
#include "datavalue.hpp"

#include <iostream>
#include <string>

class CPU : public Component
{
  public:
    CPU();
    CPU(std::istream &definition);

    // getters
    unsigned int activeCore() const;
    unsigned int cores() const;
    unsigned int frequency() const;
    std::string label() const;

    // methods
    void simulate();
    DataValue read();

  private:
    // Program program;
    // Register register;
    unsigned int activeCore_;
    unsigned int cores_;
    unsigned int frequency_;
    std::string label_;
};
