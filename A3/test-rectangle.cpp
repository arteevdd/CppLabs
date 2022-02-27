#include <boost/test/unit_test.hpp>

#include "rectangle.hpp"

BOOST_AUTO_TEST_SUITE(TestRectangle)

BOOST_AUTO_TEST_CASE(moveRectangle)
{
  double w = 4;
  double h = 5;
  arteev::point_t p{1, 2};
  arteev::point_t newPos{20, 1};
  arteev::Rectangle rect(w, h, p);

  rect.move(newPos);

  double newPosX = rect.getFrameRect().pos.x;
  double newPosY = rect.getFrameRect().pos.y;

  BOOST_CHECK_EQUAL(newPosX, newPos.x);
  BOOST_CHECK_EQUAL(newPosY, newPos.y);
}

BOOST_AUTO_TEST_CASE(scaleRectangle)
{
  const double k = 4;
  double w = 4;
  double h = 5;
  arteev::point_t p{4, 6};
  arteev::Rectangle rect(w, h, p);

  double oldWidthRectangle = rect.getFrameRect().width;
  double oldHeightRectangle = rect.getFrameRect().height;

  rect.scale(k);

  BOOST_CHECK_EQUAL(rect.getFrameRect().width, oldWidthRectangle*k);
  BOOST_CHECK_EQUAL(rect.getFrameRect().height, oldHeightRectangle*k);
}

BOOST_AUTO_TEST_CASE(getAreaRectangle)
{
  double expectedArea = 20;
  double w = 5, h = 4;
  arteev::point_t p{ 1,2 };
  arteev::Rectangle rect(w, h, p);

  double actualArea = rect.getArea();

  BOOST_CHECK_EQUAL(expectedArea, actualArea);

  rect.move(2, 3);

  actualArea = rect.getArea();
  BOOST_CHECK_EQUAL(expectedArea, actualArea);
  BOOST_CHECK_EQUAL(w, rect.getFrameRect().width);
  BOOST_CHECK_EQUAL(h, rect.getFrameRect().height);
}

BOOST_AUTO_TEST_SUITE_END()
