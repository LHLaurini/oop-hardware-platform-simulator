#include "bus.hpp"

#include "busdefinition.hpp"

#include <iostream>
#include <ranges>

Bus::Bus() = default;

Bus::Bus(const BusDefinition &definition)
    : sourceLabel_(definition.source())
    , width_(definition.width())
    , label_(definition.label())
    , numTimesRead(0)
{
}

std::string Bus::label() const
{
    return label_;
}

unsigned int Bus::width() const
{
    return width_;
}

std::string Bus::sourceLabel() const
{
    return sourceLabel_;
}

Source &Bus::source() const
{
    return **source_;
}

void Bus::bind(Source &source)
{
    source_ = &source;
}

DataValue Bus::read()
{
    if (!ready.empty())
    {
        auto value = ready.front();
        ready.pop();
        return DataValue(value);
    }
    else
    {
        return DataValue();
    }
    numTimesRead++;
}

void Bus::simulate(bool verbose)
{
    using std::views::iota;

    if (verbose)
    {
        std::clog << "Bus '" << label_ << "'\nNumber of accesses: " << numTimesRead << "\n\n";
    }

    while (!pending.empty())
    {
        ready.push(pending.front());
        pending.pop();
    }

    for ([[maybe_unused]] auto _ : iota(0U, width_))
    {
        auto value = (*source_)->read();
        if (!value.isValid())
        {
            break;
        }
        pending.push(value.get());
    }
}
