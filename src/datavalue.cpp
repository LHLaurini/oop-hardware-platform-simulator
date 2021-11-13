#include "datavalue.hpp"

DataValue::DataValue() : valid(false)
{
}

DataValue::DataValue(double value) : value(value), valid(true)
{
}

double DataValue::get() const
{
    return value;
}

bool DataValue::isValid() const
{
    return valid;
}

DataValue::operator bool() const
{
    return isValid();
}

bool DataValue::operator!() const
{
    return !isValid();
}
