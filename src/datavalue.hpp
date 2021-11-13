#pragma once

class DataValue
{
  public:
    DataValue();
    explicit DataValue(double value);
    double get() const;
    bool isValid() const;
    explicit operator bool() const;
    bool operator!() const;

  private:
    double value;
    bool valid;
};
