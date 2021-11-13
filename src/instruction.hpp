#pragma once

#include <string>
#include <tuple>

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
    Instruction(OpCode opcode, double op1, double op2);
    Instruction(const std::tuple<OpCode, double, double> &line);
    Instruction(const std::string &line);

    // methods
    double compute();

  private:
    static std::tuple<OpCode, double, double> parseLine(const std::string &line);

    OpCode opcode;
    double op1;
    double op2;
};

std::ostream &operator<<(std::ostream &stream, const Instruction &instruction);
