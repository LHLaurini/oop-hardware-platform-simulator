#include "instruction.hpp"

#include <numeric>
#include <sstream>

Instruction::Instruction() : Instruction(OpCode::NOP, {})
{
}

Instruction::Instruction(OpCode opcode, const std::vector<double> &ops) : opcode(opcode), ops(ops)
{
}

Instruction::Instruction(const std::pair<OpCode, std::vector<double>> &line) : Instruction(line.first, line.second)
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
        return std::accumulate(ops.begin(), ops.end(), 0.0);

    case OpCode::SUB:
        if (!ops.empty())
        {
            return std::accumulate(std::next(ops.begin()), ops.end(), ops.front(), std::minus<double>());
        }
        else
        {
            return 0;
        }

    case OpCode::MUL:
        return std::accumulate(ops.begin(), ops.end(), 1.0, std::multiplies<double>());

    case OpCode::DIV:
        if (!ops.empty())
        {
            return std::accumulate(std::next(ops.begin()), ops.end(), ops.front(), std::divides<double>());
        }
        else
        {
            return 0;
        }

    default:
        abort();
    }
}

std::pair<Instruction::OpCode, std::vector<double>> Instruction::parseLine(const std::string &line)
{
    std::istringstream stream(line);

    std::string mnemonic;
    std::vector<double> ops;

    stream >> mnemonic;

    for (double op; stream >> op;)
    {
        ops.emplace_back(op);
    }

    if (stream.fail() && !stream.eof())
    {
        throw std::runtime_error("extra characters after instruction");
    }

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

    return {opcode, ops};
}

std::ostream &operator<<(std::ostream &stream, const Instruction &instruction)
{
    const char *mnemonic = "";

    switch (instruction.opcode)
    {
    case Instruction::OpCode::NOP:
        mnemonic = "NOP";
        break;

    case Instruction::OpCode::ADD:
        mnemonic = "ADD";
        break;

    case Instruction::OpCode::SUB:
        mnemonic = "SUB";
        break;

    case Instruction::OpCode::MUL:
        mnemonic = "MUL";
        break;

    case Instruction::OpCode::DIV:
        mnemonic = "DIV";
        break;
    }

    stream << mnemonic;

    for (auto &op : instruction.ops)
    {
        stream << " " << op;
    }

    return stream;
}
