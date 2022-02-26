#include "shape.hpp"
#include "utils.hpp"
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

namespace art = arteev;

std::ostream& art::operator<<(std::ostream& out, const Shape& shp)
{
  out << shp.size() << ' ';
  std::copy(shp.begin(), shp.end(), std::ostream_iterator< Point >(out, " "));
  return out;
}

std::istream& art::operator>>(std::istream& in, Shape& shp)
{
  std::istream::sentry sentry(in);
  if (sentry)
  {
    size_t size = 0;
    in >> size;
    if (in.fail() || in.get() != ' ')
    {
      in.setstate(std::ios::badbit);
    }

    Shape temp;
    std::copy_n(std::istream_iterator< Point >(in), size, std::back_inserter(temp));
    if ((in.fail() && in.eof()) && !temp.empty())
    {
      in.clear();
      in.setstate(std::ios::badbit);
    }

    if (in)
    {
      std::swap(shp, temp);
    }
  }
  return in;
}

bool art::isTriangle(const Shape& shp)
{
  return shp.size() == 3;
}

bool art::isRectangle(const Shape& shp)
{
  return shp.size() == 4;
}

bool art::isSquare(const Shape& shp)
{
  int side1 = calculateVec(shp[0], shp[1]);
  int side2 = calculateVec(shp[1], shp[2]);
  int side3 = calculateVec(shp[2], shp[3]);
  int side4 = calculateVec(shp[3], shp[0]);
  return (side1 == side2) && (side1 == side3) && (side1 == side4);
}

bool art::isPentagon(const Shape& shp)
{
  return shp.size() == 5;
}

bool art::operator<(const Shape& shp1, const Shape& shp2)
{
  if (shp1.size() < 5 && shp2.size() < 5)
  {
    if (shp1.size() == 4 && shp2.size() == 4)
    {
      return isSquare(shp1) && !isSquare(shp2);
    }
  }
  return (shp1.size() < shp2.size());
}
