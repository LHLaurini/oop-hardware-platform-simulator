#pragma once

#include "datavalue.hpp"

#include <string>

class Source
{
  public:
    virtual ~Source() = default;
    virtual std::string label() const = 0;
    virtual DataValue read() = 0;
};
