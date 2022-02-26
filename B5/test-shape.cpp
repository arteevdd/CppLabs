#include <boost/test/unit_test.hpp>
#include "shape.hpp"

BOOST_AUTO_TEST_SUITE(testPoint)

BOOST_AUTO_TEST_CASE(correctPoint)
{
  std::istringstream in("(10; 2)");
  arteev::Point point;
  in >> point;
  BOOST_CHECK_EQUAL(point.x, 10);
  BOOST_CHECK_EQUAL(point.y, 2);
  BOOST_CHECK(in);
}

BOOST_AUTO_TEST_CASE(wrongPoint)
{
  std::istringstream in("(13,-11)");
  arteev::Point point;
  in >> point;
  BOOST_CHECK(in.fail());
}

BOOST_AUTO_TEST_CASE(correctShape)
{
  std::istringstream in("4 (10; 10) (10; 11) (11; 11) (11; 10)");
  arteev::Shape shape;
  in >> shape;
  BOOST_CHECK(shape.size() == 4);
  BOOST_CHECK_EQUAL(shape[0].x, 10);
  BOOST_CHECK_EQUAL(shape[0].y, 10);
  BOOST_CHECK_EQUAL(shape[1].x, 10);
  BOOST_CHECK_EQUAL(shape[1].y, 11);
  BOOST_CHECK_EQUAL(shape[2].x, 11);
  BOOST_CHECK_EQUAL(shape[2].y, 11);
  BOOST_CHECK_EQUAL(shape[3].x, 11);
  BOOST_CHECK_EQUAL(shape[3].y, 10);
}

BOOST_AUTO_TEST_CASE(wrongShape)
{
  std::istringstream in("4 (2; 15) (4; 16) ");
  arteev::Shape shape;
  in >> shape;
  BOOST_CHECK(in.fail());
}


BOOST_AUTO_TEST_SUITE_END()
