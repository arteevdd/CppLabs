#include "util.hpp"

namespace art = arteev;

bool art::checkSteps(const std::string& steps)
{
  if (steps == "last" || steps == "first")
  {
    return true;
  }

  return checkDigits(steps);
}

bool art::checkDigits(const std::string& s, bool checkPlusMinus)
{
  if (s.empty())
  {
    return false;
  }

  auto beg = s.begin();
  if (checkPlusMinus)
  {
    if (s[0] == '-' || s[0] == '+')
    {
      beg++;
    }
  }

  if (std::all_of(beg, s.end(), ::isdigit))
  {
    return true;
  }

  return false;
}

std::string art::read(std::istream& in)
{
  std::string line;
  in >> line;
  if (in.fail() && !in.eof())
  {
    throw std::runtime_error("<INPUT ERROR>");
  }

  return line;
}

std::string art::readName(std::istream& in)
{
  std::string name;
  in >> std::ws;
  std::getline(in, name);
  if (name.size() < 2 || name.front() != '"' || name.back() != '"')
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
  name = name.substr(1, name.length() - 2);
  name.erase(std::remove(name.begin(), name.end(), '\\'), name.end());
  return name;
}

bool art::checkMarkName(const std::string& markName)
{
  for (const char& ch: markName)
  {
    if (!isalpha(ch) && !isdigit(ch) && ch != '-')
    {
      return false;
    }
  }
  return true;
}

bool art::checkInsertMode(const std::string& mode)
{
  return mode == "before" || mode == "after";
}
