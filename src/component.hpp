#pragma once

class Component
{
  public:
    virtual ~Component() = default;
    virtual void simulate() = 0;
};
