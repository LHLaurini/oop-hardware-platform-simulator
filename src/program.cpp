#include "program.hpp"

#include <fstream>

Program::Program() = default;

Program::Program(const std::filesystem::path &path) : instructionPointer(0)
{
    std::ifstream stream(path);
    if (!stream)
    {
        throw std::runtime_error("failed to open file " + path.string());
    }

    for (std::string line; std::getline(stream, line);)
    {
        instructions.emplace_back(line);
    }
}

bool Program::finished() const
{
    return instructionPointer >= instructions.size();
}

Instruction Program::compute()
{
    if (!finished())
    {
        return instructions.at(instructionPointer++);
    }
    else
    {
        return {};
    }
}

void Program::restart()
{
    instructionPointer = 0;
}
