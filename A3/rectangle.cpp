#include "rectangle.hpp"
#include <cassert>

namespace art = arteev;

art::Rectangle::Rectangle(const double width, const double height, const art::point_t& pos):
  width_(width),
  height_(height),
  pos_(pos)
{
 assert (width > 0 && height > 0);
}

double art::Rectangle::getArea() const
{
  return (width_ * height_);
}

art::rectangle_t art::Rectangle::getFrameRect() const
{
  return {width_, height_, pos_};
}

void art::Rectangle::move(const art::point_t point)
{
  pos_ = point;
}

void art::Rectangle::move(const double dx, const double dy)
{
  pos_.x += dx;
  pos_.y += dy;
}

void art::Rectangle::scale(const double k)
{
  width_ *= k;
  height_ *= k;
}

art::Shape::UniquePtr art::Rectangle::clone() const
{
  return std::make_unique< art::Rectangle >(*this);
}

std::string art::Rectangle::getName() const
{
  return "Rectangle";
}
