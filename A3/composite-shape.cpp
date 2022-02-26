#include "composite-shape.hpp"
#include <cassert>

namespace art = arteev;

art::CompositeShape::CompositeShape(UniquePtr shape):
  capacity_(2),
  size_(1),
  array_(std::make_unique< UniquePtr[] >(capacity_))
{
  assert(shape == nullptr);

  array_[size_ - 1] = shape->clone();
}

art::CompositeShape::CompositeShape(const CompositeShape& other):
  capacity_(other.capacity_),
  size_(other.size_),
  array_(std::make_unique< UniquePtr[] >(other.capacity_))
{
  for (int i = 0; i < size_; i++)
  {
    array_[i] = other.array_[i]->clone();
  }
}

double art::CompositeShape::getArea() const
{
  double totalArea = 0;
  for (int i = 0; i < size_; i++)
  {
    totalArea += array_[i]->getArea();
  }
  return totalArea;
}

art::rectangle_t art::CompositeShape::getFrameRect() const
{
  double maxX = getX(array_[0]) + getWidth(array_[0]) / 2;
  double minX = getX(array_[0]) - getWidth(array_[0]) / 2;
  double maxY = getY(array_[0]) + getHeight(array_[0]) / 2;
  double minY = getY(array_[0]) - getHeight(array_[0]) / 2;

  for (int i = 1; i < size_; i++)
  {
    maxX = std::max(maxX, getX(array_[i]) + getWidth(array_[i]) / 2);
    maxY = std::max(maxY, getY(array_[i]) + getHeight(array_[i]) / 2);
    minX = std::min(minX, getX(array_[i]) - getWidth(array_[i]) / 2);
    minY = std::min(minY, getY(array_[i]) - getHeight(array_[i]) / 2);
  }
  return {maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2}};
}

art::Shape::UniquePtr art::CompositeShape::clone() const
{
  return std::make_unique< art::CompositeShape >(*this);
}

void art::CompositeShape::move(const art::point_t point)
{
  double dx = point.x - getFrameRect().pos.x;
  double dy = point.y - getFrameRect().pos.y;
  for (int i = 0; i < size_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

void art::CompositeShape::move(double dx, double dy)
{
  for (int i = 0; i < size_; i++)
  {
    array_[i]->move(dx, dy);
  }
}

void art::CompositeShape::scale(double k)
{
  double compositeX = getFrameRect().pos.x;
  double compositeY = getFrameRect().pos.y;

  for (int i = 0; i < size_; i++)
  {
    double dx = getX(array_[i]) - compositeX;
    double dy = getY(array_[i]) - compositeY;
    double xNew = compositeX + dx * k;
    double yNew = compositeY + dy * k;
    point_t newPoint = {xNew, yNew};
    array_[i]->move(newPoint);
    array_[i]->scale(k);
  }
}

std::string art::CompositeShape::getName() const
{
  return "Composite Shape";
}
