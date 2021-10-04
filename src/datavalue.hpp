#pragma once

class DataValue
{
  public:
    DataValue();
    DataValue(double value);

    double get() const
    {
        return value;
    }

    bool isValid() const
    {
        return valid;
    }

    operator double() const
    {
        return value;
    }

    operator bool() const
    {
        return isValid();
    }

    bool operator!() const
    {
        return !isValid();
    }

  private:
    double value;
    bool valid;
};
