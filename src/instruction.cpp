#include "instruction.hpp"

#include <sstream>

Instruction::Instruction() : Instruction(OpCode::NOP, 0, 0)
{
}

Instruction::Instruction(OpCode opcode, double op1, double op2) : opcode(opcode), op1(op1), op2(op2)
{
}

Instruction::Instruction(const std::tuple<OpCode, double, double> &line)
    : Instruction(std::get<0>(line), std::get<1>(line), std::get<2>(line))
{
}

Instruction::Instruction(const std::string &line) : Instruction(parseLine(line))
{
}

double Instruction::compute()
{
    switch (opcode)
    {
    case OpCode::NOP:
        return 0;

    case OpCode::ADD:
        return op1 + op2;

    case OpCode::SUB:
        return op1 - op2;

    case OpCode::MUL:
        return op1 * op2;

    case OpCode::DIV:
        return op1 / op2;

    default:
        abort();
    }
}

std::tuple<Instruction::OpCode, double, double> Instruction::parseLine(const std::string &line)
{
    std::istringstream stream(line);

    std::string mnemonic;
    double op1, op2;

    stream >> mnemonic >> op1 >> op2;

    OpCode opcode;

    if (mnemonic == "NOP")
    {
        opcode = OpCode::NOP;
    }
    else if (mnemonic == "ADD")
    {
        opcode = OpCode::ADD;
    }
    else if (mnemonic == "SUB")
    {
        opcode = OpCode::SUB;
    }
    else if (mnemonic == "MUL")
    {
        opcode = OpCode::MUL;
    }
    else if (mnemonic == "DIV")
    {
        opcode = OpCode::DIV;
    }
    else
    {
        throw std::runtime_error("invalid instruction");
    }

    return {opcode, op1, op2};
}
