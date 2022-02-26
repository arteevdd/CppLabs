#include "rectangle.hpp"

Rectangle::Rectangle(double width, double height, point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{
}

double Rectangle::getArea() const
{
  return (width_ * height_);
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(point_t pos)
{
  pos_ = pos;
}

void Rectangle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
