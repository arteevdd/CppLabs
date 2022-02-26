#ifndef COUNTER_HPP
#define COUNTER_HPP

#include "shape.hpp"

namespace arteev
{
  struct Counter
  {
    int vertices;
    int triangles;
    int rectangles;
    int squares;

    void operator()(const Shape& shp);
  };
  std::ostream& operator<<(std::ostream& out, Counter& counter);
}
#endif