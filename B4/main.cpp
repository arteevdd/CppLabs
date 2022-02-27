#include <iterator>
#include <iostream>
#include <vector>
#include <algorithm>

#include "data-struct.hpp"

int main()
{
  std::istream_iterator< arteev::DataStruct > start(std::cin);
  std::istream_iterator< arteev::DataStruct > finish;
  std::vector< arteev::DataStruct > vec(start, finish);
  if (std::cin.fail() && !std::cin.eof())
  {
    return 2;
  }
  std::sort(vec.begin(), vec.end());
  std::copy(vec.begin(), vec.end(), std::ostream_iterator< arteev::DataStruct >(std::cout, "\n"));
}
