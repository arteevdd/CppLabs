#include "tasks.hpp"
#include "utils.hpp"

#include <stdexcept>
#include <vector>

void arteev::task3()
{
  std::vector< int > v;
  int n = 0;
  while(std::cin >> n)
  {
    if (n == 0)
    {
      break;
    }
    v.push_back(n);
  }
  if ((n != 0) || (!std::cin.eof() && std::cin.fail()) || std::cin.bad())
  {
    throw(std::runtime_error("Incorrect input\n"));
  }

  if (!v.empty())
  {
    if (v.back() == 1)
    {
      auto it = v.begin();
      while (it != v.end())
      {
        if (*it % 2 == 0)
        {
          it = v.erase(it);
        }
        else
        {
          ++it;
        }
      }
    }
  else if (v.back() == 2)
  {
    auto it = v.begin();
    while (it != v.end())
    {
      if (*it % 3 == 0)
      {
        it = v.insert(it + 1, { 1,1,1 });
      }
      else
      {
        ++it;
      }
    }
  }

  print(v.begin(), v.end(), std::cout);
  }
}
