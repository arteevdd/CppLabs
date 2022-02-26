#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <vector>
#include <functional>
#include <random>
#include <cstring>

namespace arteev
{
  template< typename T >
  std::function< bool(T, T) > comparator(const char* order)
  {
    if (!strcmp(order, "descending"))
    {
      return std::greater< T >();
    }
    if (!strcmp(order, "ascending"))
    {
      return std::less< T >();
    }
    throw(std::invalid_argument("Incorrect order\n"));
  }

  template< typename T >
  void print(T first, T end, std::ostream& os)
  {
    while (first != end)
    {
      os << *first << " ";
      first++;
    }
    os << std::endl;
  }

  bool checkNumber(const char* string);

  void fillRand(double* array, int size);
}

#endif
