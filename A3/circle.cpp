#include "circle.hpp"
#include <string>
#include <cassert>

namespace art = arteev;

constexpr double PI = 3.14;

art::Circle::Circle(const double radius, const art::point_t& pos):
  radius_(radius),
  pos_(pos)
{
  assert (radius >= 0);
}

double art::Circle::getArea() const
{
  return (PI * radius_ * radius_);
}

art::rectangle_t art::Circle::getFrameRect() const
{
  return {2 * radius_, 2 * radius_, pos_};
}

void art::Circle::move(const art::point_t point)
{
  pos_ = point;
}

void art::Circle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void art::Circle::scale(const double k)
{
  assert(k >= 0);

  radius_ *= k;
}

art::Shape::UniquePtr art::Circle::clone() const
{
  return std::make_unique< art::Circle >(*this);
}

std::string art::Circle::getName() const
{
  return "Circle";
}
