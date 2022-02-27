#include "tasks.hpp"
#include "sort.hpp"
#include "access-policies.hpp"
#include "utils.hpp"

#include <forward_list>
#include <stdexcept>
#include <vector>

void arteev::task1(const char* order)
{
  std::vector< int > v;
  int x;
  while (std::cin >> x)
  {
    v.push_back(x);
  }

  if (std::cin.fail() && !std::cin.eof())
  {
    throw std::invalid_argument("Incorrect input");
  }

  std::function< bool(int, int) > cmp = comparator<int>(order);

  std::vector< int > v2 = v;

  std::forward_list< int > flist(v.begin(), v.end());
  selection_sort< int, indexPolicy >(v, cmp);
  selection_sort< int, atPolicy >(v2, cmp);
  selection_sort< int, iteratorPolicy >(flist, cmp);

  print(v.begin(), v.end(), std::cout);
  print(v2.begin(), v2.end(), std::cout);
  print(flist.begin(), flist.end(), std::cout);
}
