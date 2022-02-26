#include <boost/test/unit_test.hpp>

#include "container.hpp"

BOOST_AUTO_TEST_SUITE(testFactorial)

BOOST_AUTO_TEST_CASE(factorial)
{
    arteev::Container fc;
    arteev::Container::Iterator iterator = fc.begin();
    unsigned int factorial = 1;
    size_t i = 2;
    while (iterator != fc.end())
    {
      BOOST_CHECK(*iterator == factorial);
      factorial*= i;
      i++;
      iterator++;
    }
}

BOOST_AUTO_TEST_SUITE_END()
