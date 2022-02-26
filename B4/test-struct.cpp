#include <boost/test/unit_test.hpp>

#include "data-struct.hpp"

#include <sstream>
#include <algorithm>

BOOST_AUTO_TEST_SUITE(testStruct)

  BOOST_AUTO_TEST_CASE(correctInput)
  {
    arteev::DataStruct dataStruct;
    std::stringstream stream("4,0,correctStr");
    stream >> dataStruct;
    BOOST_CHECK_EQUAL(dataStruct.key1, 4);
    BOOST_CHECK_EQUAL(dataStruct.key2, 0);
    BOOST_CHECK_EQUAL(dataStruct.str, "correctStr");
  }

  BOOST_AUTO_TEST_CASE(incorrectFirstComma)
  {
    arteev::DataStruct dataStruct;
    std::stringstream stream("40,0,sdsadada");
    stream >> dataStruct;
    BOOST_CHECK(stream.fail());
  }

  BOOST_AUTO_TEST_CASE(incorrectSecondComma)
  {
    arteev::DataStruct dataStruct;
    std::stringstream stream("2,13,sdsadada");
    stream >> dataStruct;
    BOOST_CHECK(stream.fail());
  }

  BOOST_AUTO_TEST_CASE(incorrectStr)
  {
    arteev::DataStruct dataStruct;
    std::stringstream stream("2,13,");
    stream >> dataStruct;
    BOOST_CHECK(stream.fail());
  }

BOOST_AUTO_TEST_SUITE_END()
