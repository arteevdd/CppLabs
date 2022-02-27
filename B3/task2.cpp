#include "tasks.hpp"
#include "container.hpp"

#include <algorithm>
#include <ostream>

void arteev::task2(std::ostream& out)
{
  Container it;
  std::copy(it.begin(), it.end(), std::ostream_iterator<size_t>(out, " "));
  out << '\n';
  std::reverse_copy(it.begin(), it.end(), std::ostream_iterator<size_t>(out, " "));
  out << '\n';
}