#pragma once

class Component
{
  public:
    virtual ~Component() = default;
    virtual void simulate(bool verbose) = 0;
    virtual unsigned int priority() const = 0;
};
