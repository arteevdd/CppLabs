#include <boost/test/unit_test.hpp>

#include "circle.hpp"

BOOST_AUTO_TEST_SUITE(TestCircle)

BOOST_AUTO_TEST_CASE(moveCircle)
{
  double radius = 2;
  arteev::point_t p{ 1,2 };
  arteev::point_t newPos{6, 6};
  arteev::Circle circ(radius, p);

  circ.move(newPos);

  double newPosX = circ.getFrameRect().pos.x;
  double newPosY = circ.getFrameRect().pos.y;

  BOOST_CHECK_EQUAL(newPosX, newPos.x);
  BOOST_CHECK_EQUAL(newPosY, newPos.y);
}

BOOST_AUTO_TEST_CASE(scaleCircle)
{
  const double k = 5;
  double radius = 2;
  arteev::point_t p{ 1,2 };
  arteev::Circle circ(radius, p);

  double oldRadius = circ.getFrameRect().width/2;

  circ.scale(k);

  BOOST_CHECK_EQUAL(circ.getFrameRect().width/2, oldRadius*k);
}


BOOST_AUTO_TEST_CASE(getAreaCircle)
{
  double expectedArea = 12.56;
  double radius = 2;
  arteev::point_t p{ 1,2 };
  arteev::Circle circ(radius, p);

  double actualArea = circ.getArea();
  BOOST_CHECK_EQUAL(expectedArea, actualArea);
}

BOOST_AUTO_TEST_SUITE_END()
