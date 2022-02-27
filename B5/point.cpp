#include "point.hpp"

#include <iostream>

std::ostream& arteev::operator<<(std::ostream& out, const arteev::Point& point)
{
  out << '(' << point.x << ';' << point.y << ')';
  return out;
}

std::istream& arteev::operator>>(std::istream& in, arteev::Point& point)
{
  in >> std::ws;
  if (!in || in.get() != '(')
  {
    in.clear();
    in.setstate(std::ios_base::failbit);
    return in;
  }

  in >> std::ws >> point.x >> std::ws;
  if (!in || in.get() != ';')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }

  in >> std::ws >> point.y >> std::ws;
  if (!in || in.get() != ')')
  {
    in.setstate(std::ios_base::failbit);
    return in;
  }
  return in;
}