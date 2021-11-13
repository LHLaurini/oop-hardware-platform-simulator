#pragma once

#include <string>
#include <utility>
#include <vector>

class Instruction
{
    friend std::ostream &operator<<(std::ostream &stream, const Instruction &instruction);

  public:
    enum class OpCode
    {
        NOP,
        ADD,
        SUB,
        MUL,
        DIV
    };

    Instruction();
    Instruction(OpCode opcode, const std::vector<double> &ops);
    Instruction(const std::pair<OpCode, std::vector<double>> &line);
    Instruction(const std::string &line);

    // methods
    double compute();

  private:
    static std::pair<OpCode, std::vector<double>> parseLine(const std::string &line);

    OpCode opcode;
    std::vector<double> ops;
};

std::ostream &operator<<(std::ostream &stream, const Instruction &instruction);
