#ifndef UTIL_HPP
#define UTIL_HPP

#include <iostream>
#include <string>
#include <algorithm>

namespace arteev 
{
  bool checkSteps(const std::string& steps);
  bool checkDigits(const std::string& s, bool checkPlusMinus = true);

  std::string read(std::istream& in);
  std::string readName(std::istream& in);
  bool checkMarkName(const std::string& markName);
  bool checkInsertMode(const std::string& mode);

  constexpr unsigned long getFactorial(unsigned int num)
  {
    if (num < 2)
    {
      return 1;
    }
    return num * getFactorial(num - 1);
  }
}

#endif
