#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <memory>
#include "shape.hpp"
#include "base-types.hpp"

namespace arteev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(double width, double height, const point_t& pos_);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t point) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
    UniquePtr clone() const override;
    std::string getName() const override;
  private:
    double width_;
    double height_;
    point_t pos_;
  };
}

#endif
