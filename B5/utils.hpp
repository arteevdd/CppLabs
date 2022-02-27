#ifndef UTILS_HPP
#define UTILS_HPP

#include "point.hpp"
#include "shape.hpp"

namespace arteev
{
  Point getPeak(const Shape& shp);
  int calculateVec(const Point& first, const Point& second);
}

#endif