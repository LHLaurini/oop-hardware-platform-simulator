#include "reader.hpp"

#include <algorithm>
#include <stdexcept>

namespace
{
constexpr auto whitespace = " \t";

bool isSpace(char c)
{
    return std::isspace(c);
}

std::string stripWhitespace(const std::string &string)
{
    auto spacesAtBeginning = std::find_if_not(string.begin(), string.end(), isSpace) - string.begin();
    auto spacesAtEnd = std::find_if_not(string.rbegin(), string.rend(), isSpace) - string.rbegin();
    return string.substr(spacesAtBeginning, string.size() - spacesAtEnd - spacesAtBeginning);
}
} // namespace

Reader::Reader(std::istream &stream)
{
    std::string line;
    while (std::getline(stream, line))
    {
        if (line.find_first_not_of(whitespace) == std::string::npos)
        {
            continue;
        }

        auto separatorPos = line.find(':');

        if (separatorPos == std::string::npos)
        {
            throw std::runtime_error("invalid line");
        }

        auto key = stripWhitespace(line.substr(0, separatorPos));
        auto value = stripWhitespace(line.substr(separatorPos + 1));
        values.emplace(key, value);
    }
}

Reader::Values::const_iterator Reader::begin() const
{
    return values.begin();
}

Reader::Values::const_iterator Reader::end() const
{
    return values.end();
}
