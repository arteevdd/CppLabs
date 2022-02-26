#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <vector>
#include "point.hpp"

namespace arteev
{
  using Shape = std::vector< Point >;

  std::ostream& operator<<(std::ostream& out, const Shape& shp);
  std::istream& operator>>(std::istream& in, Shape& shp);
  bool isTriangle(const Shape& shp);
  bool isRectangle(const Shape& shp);
  bool isSquare(const Shape& shp);
  bool isPentagon (const Shape& shp);

  bool operator<(const Shape& shp1, const Shape& shp2);
}

#endif
