#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include <memory>
#include "base-types.hpp"

namespace arteev
{
  class Shape
  {
  public:
    using UniquePtr = std::unique_ptr < Shape >;

    virtual std::string getName() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual UniquePtr clone() const = 0;
    virtual void move(const point_t point) = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
  };
  double getX(const Shape::UniquePtr& shp);
  double getY(const Shape::UniquePtr& shp);
  double getWidth(const Shape::UniquePtr& shp);
  double getHeight(const Shape::UniquePtr& shp);
}

#endif

