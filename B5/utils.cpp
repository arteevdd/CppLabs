#include "utils.hpp"
#include <algorithm>

namespace art = arteev;

art::Point art::getPeak(const Shape& shp)
{
  return shp.front();
}

int art::calculateVec(const Point& first, const Point& second)
{
  int x = second.x - first.x;
  int y = second.y - first.y;
  return (x * x + y * y);
}
