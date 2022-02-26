#include "circle.hpp"

const double PI = 3.14;

Circle::Circle(point_t pos, double radius):
  radius_(radius),
  pos_(pos)
{
}

double Circle::getArea() const
{
  return  (PI * radius_ * radius_);
}

rectangle_t Circle::getFrameRect() const
{
  return { 2 * radius_, 2 * radius_, pos_ };
}

void Circle::move(point_t pos)
{
  pos_ = pos;
}

void Circle::move(double dx, double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}
