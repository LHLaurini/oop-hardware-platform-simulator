#include "cpu.hpp"

#include "cpudefinition.hpp"

#include <fstream>
#include <ranges>

CPU::CPU() = default;

CPU::CPU(const CPUDefinition &definition)
    : program(definition.program())
    , activeCore_(0)
    , cores_(definition.cores())
    , frequency_(definition.frequency())
    , label_(definition.label())
{
}

unsigned int CPU::activeCore() const
{
    return activeCore_;
}

unsigned int CPU::cores() const
{
    return cores_;
}

unsigned int CPU::frequency() const
{
    return frequency_;
}

std::string CPU::label() const
{
    return label_;
}

void CPU::simulate()
{
    using std::views::iota;

    for ([[maybe_unused]] auto _ : iota(0U, frequency_))
    {
        if (program.finished() && activeCore_ < cores_ - 1)
        {
            activeCore_++;
            program.restart();
        }

        register_.write(program.compute().compute());
    }
}

DataValue CPU::read()
{
    return register_.read();
}
