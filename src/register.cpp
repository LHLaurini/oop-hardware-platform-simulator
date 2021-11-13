#include "register.hpp"

Register::Register() = default;

bool Register::empty() const
{
    return values.empty();
}

DataValue Register::read()
{
    if (!empty())
    {
        double value = values.front();
        values.pop();
        return DataValue(value);
    }
    else
    {
        return {};
    }
}

void Register::write(double value)
{
    values.push(value);
}
