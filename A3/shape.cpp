#include "shape.hpp"

namespace art = arteev;

double art::getX(const Shape::UniquePtr& shp)
{
  return shp->getFrameRect().pos.x;
}

double art::getY(const Shape::UniquePtr& shp)
{
  return shp->getFrameRect().pos.y;
}

double art::getWidth(const Shape::UniquePtr& shp)
{
  return shp->getFrameRect().width;
}

double art::getHeight(const Shape::UniquePtr& shp)
{
  return shp->getFrameRect().height;
}

