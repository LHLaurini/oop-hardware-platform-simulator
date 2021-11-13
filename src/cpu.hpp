#pragma once

#include "component.hpp"
#include "datavalue.hpp"
#include "program.hpp"
#include "register.hpp"
#include "source.hpp"

#include <string>

class CPUDefinition;

class CPU : public Component, public Source
{
  public:
    CPU();
    CPU(const CPUDefinition &definition);

    // getters
    unsigned int activeCore() const;
    unsigned int cores() const;
    unsigned int frequency() const;
    std::string label() const override;

    // methods
    void simulate() override;
    DataValue read() override;

  private:
    Program program;
    Register register_;
    unsigned int activeCore_;
    unsigned int cores_;
    unsigned int frequency_;
    std::string label_;
};
