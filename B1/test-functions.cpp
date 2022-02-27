#include <boost/test/unit_test.hpp>

#include "utils.hpp"

BOOST_AUTO_TEST_SUITE(CheckInPut)

BOOST_AUTO_TEST_CASE(CheckNumber)
{
  BOOST_CHECK(arteev::checkNumber("2222"));
  BOOST_CHECK(!arteev::checkNumber("41 16"));
  BOOST_CHECK(!arteev::checkNumber("kekW"));
  BOOST_CHECK(!arteev::checkNumber("weq$ a"));

}

BOOST_AUTO_TEST_CASE(CheckArg)
{
  BOOST_CHECK(arteev::comparator< int >("ascending"));
  BOOST_CHECK(arteev::comparator< int >("descending"));
  BOOST_CHECK_THROW(arteev::comparator< int >(""), std::invalid_argument);
  BOOST_CHECK_THROW(arteev::comparator< int >("riopoipo"), std::invalid_argument);
  BOOST_CHECK_THROW(arteev::comparator< int >("312"), std::invalid_argument);
}

BOOST_AUTO_TEST_SUITE_END()
