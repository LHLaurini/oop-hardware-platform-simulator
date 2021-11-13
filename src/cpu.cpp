#include "cpu.hpp"

#include "cpudefinition.hpp"

#include <iostream>
#include <ranges>

CPU::CPU() = default;

CPU::CPU(const CPUDefinition &definition)
    : program(definition.program())
    , activeCore_(0)
    , cores_(definition.cores())
    , frequency_(definition.frequency())
    , label_(definition.label())
    , priority_(definition.priority())
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

unsigned int CPU::priority() const
{
    return priority_;
}

void CPU::simulate(bool verbose)
{
    using std::views::iota;

    if (verbose)
    {
        std::clog << "CPU '" << label_ << "'\nNumber of cores: " << cores_ << "\nFrequency: " << frequency_;
    }

    for ([[maybe_unused]] auto _ : iota(0U, frequency_))
    {
        if (program.finished() && activeCore_ < cores_ - 1)
        {
            activeCore_++;
            program.restart();
        }

        auto instruction = program.compute();
        auto result = instruction.compute();

        if (verbose)
        {
            std::clog << "\nActive core: " << activeCore_ << "\nInstruction: " << instruction << "\nResult: " << result;
        }

        register_.write(result);
    }

    if (verbose)
    {
        std::clog << "\n\n";
    }
}

DataValue CPU::read()
{
    return register_.read();
}
