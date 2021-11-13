#include "memory.hpp"

Memory::Memory() = default;

Memory::Memory(const MemoryDefinition &definition)
    : sourceLabel_(definition.source())
    , size_(definition.size())
    , accessTime_(definition.access())
    , label_(definition.label())
    , data(std::make_unique<double[]>(size_))
    , numWait(accessTime_)
    , readHead(0)
    , writeHead(0)
{
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

void Memory::bind(Source &source)
{
    source_ = &source;
}

void Memory::simulate()
{
    if (--numWait < 0)
    {
        numWait = accessTime_;

        while (auto value = (*source_)->read())
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
    if (nextPosition(writeHead) == readHead)
    {
        // throw std::runtime_error("memory is full");
    }

    data[writeHead] = value;

    writeHead = nextPosition(writeHead);
}
