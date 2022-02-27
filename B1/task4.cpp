#include "tasks.hpp"
#include "utils.hpp"
#include "sort.hpp"
#include "access-policies.hpp"

void arteev::task4(const char* order, int size)
{
  std::function< bool(double, double) > cmp = comparator< double >(order);

  std::vector< double > v(size);
  fillRand(v.data(), size);
  print(v.begin(), v.end(), std::cout);
  selection_sort< double, indexPolicy >(v, cmp);
  print(v.begin(), v.end(), std::cout);
}
