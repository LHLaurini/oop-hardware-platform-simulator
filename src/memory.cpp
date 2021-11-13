#include "memory.hpp"

#include <iostream>

Memory::Memory() = default;

Memory::Memory(const MemoryDefinition &definition)
    : sourceLabel_(definition.source())
    , size_(definition.size())
    , accessTime_(definition.access())
    , label_(definition.label())
    , data(std::make_unique<double[]>(size_))
    , numWait(accessTime_)
    , readHead(0)
    , writeHead(definition.init().size())
    , priority_(definition.priority())
{
    if (definition.init().size() > size_ - 1)
    {
        throw std::runtime_error("too much data for INIT");
    }

    std::ranges::copy(definition.init(), data.get());
}

std::string Memory::label() const
{
    return label_;
}

unsigned int Memory::size() const
{
    return size_;
}

std::time_t Memory::accessTime() const
{
    return accessTime_;
}

Source &Memory::source() const
{
    return **source_;
}

std::string Memory::sourceLabel() const
{
    return sourceLabel_;
}

unsigned int Memory::priority() const
{
    return priority_;
}

void Memory::bind(Source &source)
{
    source_ = &source;
}

void Memory::simulate(bool verbose)
{
    if (verbose)
    {
        const auto unread = (writeHead - readHead + size_) % size_;

        std::clog << "Memory '" << label_ << "'\nAccess time: " << accessTime_
                  << "\nNumber of unread values: " << unread << "\nNumber of free places: " << size_ - unread << "\n\n";
    }

    if (--numWait < 0)
    {
        numWait = accessTime_;

        // Only read while there is space and valid data

        for (DataValue value; nextPosition(writeHead) != readHead && (value = (*source_)->read());)
        {
            write(value.get());
        }
    }
}

DataValue Memory::read()
{
    if (readHead != writeHead)
    {
        double value = data[readHead];
        readHead = nextPosition(readHead);

        return DataValue(value);
    }
    else
    {
        return DataValue();
    }
}

std::size_t Memory::nextPosition(std::size_t position)
{
    if (++position >= size_)
    {
        position -= size_;
    }
    return position;
}

void Memory::write(double value)
{
    data[writeHead] = value;

    writeHead = nextPosition(writeHead);
}
