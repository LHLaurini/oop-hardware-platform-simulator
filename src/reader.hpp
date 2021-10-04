#pragma once

#include <iostream>
#include <map>
#include <string>

class Reader
{
  public:
    using Values = std::map<std::string, std::string>;

    Reader(std::istream &stream);
    Values::const_iterator begin() const;
    Values::const_iterator end() const;

  private:
    Values values;
};
