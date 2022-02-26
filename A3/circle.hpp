#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace arteev
{
  class Circle: public Shape
  {
  public:
    Circle(double radius, const point_t& pos);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    UniquePtr clone() const override;
    std::string getName() const override;
  private:
    double radius_;
    point_t pos_;
  };
}

#endif
