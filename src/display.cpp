#include "display.hpp"

#include <iostream>

Display::Display() = default;

Display::Display(const DisplayDefinition &definition)
    : sourceLabel_(definition.source())
    , refresh_(definition.refresh())
    , numWait(refresh_)
{
}

int Display::refresh() const
{
    return refresh_;
}

Source &Display::source() const
{
    return **source_;
}

std::string Display::sourceLabel() const
{
    return sourceLabel_;
}

void Display::bind(Source &source)
{
    source_ = &source;
}

void Display::simulate()
{
    if (--numWait < 0)
    {
        numWait = refresh_;
        while (auto value = (*source_)->read())
        {
            std::cout << value.get() << "\n";
        }
    }
}
