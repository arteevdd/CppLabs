#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"
#include "circle.hpp"
#include "composite-shape.hpp"

namespace art = arteev;

BOOST_AUTO_TEST_SUITE(TestMoveAndScale)

BOOST_AUTO_TEST_CASE(moveShapes)
{
  const int size = 2;
  double w = 3;
  double h = 2;
  art::point_t p1 = {12, 12};

  double radius = 3;
  art::point_t p2 = {4, 3};

  art::point_t p3 = {6, 6};

  art::CompositeShape::UniqueShape shapes = std::make_unique< art::Shape::UniquePtr[] >(size);
  shapes[0] = std::make_unique< art::Rectangle >(art::Rectangle(w, h, p1));
  shapes[1] = std::make_unique< art::Circle >(art::Circle(radius, p2));


  for (int i = 0; i < size; i++)
  {
    shapes[i]->move(p3);
  }

  art::point_t pos = shapes[0]->getFrameRect().pos;

  BOOST_CHECK_EQUAL(pos.x, p3.x);
  BOOST_CHECK_EQUAL(pos.y, p3.y);

  pos = shapes[1]->getFrameRect().pos;
  BOOST_CHECK_EQUAL(pos.x, p3.x);
  BOOST_CHECK_EQUAL(pos.y, p3.y);
}

BOOST_AUTO_TEST_CASE(scaleShapes)
{
  const int size = 2;
  const double k = 69;

  double w = 3;
  double h = 2;
  art::point_t p1 = {12, 12};

  double radius = 3;
  art::point_t p2 = {4, 3};

  art::CompositeShape::UniqueShape shapes = std::make_unique< art::Shape::UniquePtr[] >(size);
  shapes[0] = std::make_unique< art::Rectangle >(art::Rectangle(w, h, p1));
  shapes[1] = std::make_unique< art::Circle >(art::Circle(radius, p2));

  double oldWidthRectangle = shapes[0]->getFrameRect().width;
  double oldHeightRectangle = shapes[0]->getFrameRect().height;

  double oldRadius = shapes[1]->getFrameRect().height/2;

  for (int i = 0; i < size; i++)
  {
    shapes[i]->scale(k);
  }

  BOOST_CHECK_EQUAL(w, oldWidthRectangle);
  BOOST_CHECK_EQUAL(h, oldHeightRectangle);

  BOOST_CHECK_EQUAL(radius, oldRadius);
}


BOOST_AUTO_TEST_SUITE_END()
