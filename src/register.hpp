#pragma once

#include "component.hpp"
#include "datavalue.hpp"

#include <queue>

class Register
{
  public:
    Register();

    // getters
    bool empty() const;

    // methods
    DataValue read();
    void write(double value);

  private:
    std::queue<double> values;
};