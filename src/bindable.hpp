#pragma once

#include <string>

class Source;

class Bindable
{
  public:
    virtual void bind(Source &source) = 0;
    virtual std::string sourceLabel() const = 0;
    virtual Source &source() const = 0;
};
