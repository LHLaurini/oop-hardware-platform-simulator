#pragma once

#include <filesystem>
#include <iostream>
#include <vector>

#include "instruction.hpp"

class Program
{
  public:
    Program();
    Program(const std::filesystem::path &path);

    bool finished() const;

    // methods
    Instruction compute();
    void restart();

  private:
    std::vector<Instruction> instructions;
    std::size_t instructionPointer;
};