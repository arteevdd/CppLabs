#include <iostream>
#include <stdexcept>

#include "tasks.hpp"
#include "utils.hpp"

namespace art = arteev;

int main(int argc, char* argv[])
{
  srand(time(0));

  try
  {
    if ((argc < 2) || (argc > 4))
    {
      throw(std::invalid_argument("Incorrect count of arguments"));
    }
    if (!art::checkNumber(argv[1]))
    {
      throw(std::invalid_argument("Incorrect argument"));
    }
    int taskNumber = atoi(argv[1]);
    if (taskNumber == 1)
    {
      if (argc != 3)
      {
        throw(std::invalid_argument("Incorrect count of arguments"));
      }
      art::task1(argv[2]);
    }
    else if (taskNumber == 2)
    {
      if (argc != 3)
      {
        throw(std::invalid_argument("Incorrect count of arguments"));
      }
      art::task2(argv[2]);
    }
    else if (taskNumber == 3)
    {
      if (argc != 2)
      {
        throw(std::invalid_argument("Incorrect count of arguments"));
      }
      art::task3();
    }
    else if (taskNumber == 4)
    {
      if (argc != 4)
      {
        throw(std::invalid_argument("Incorrect count of arguments"));
      }
      if (!art::checkNumber(argv[3]))
      {
        throw(std::invalid_argument("Incorrect argument"));
      }
      if (atoi(argv[3]) <= 0)
      {
        throw(std::invalid_argument("Incorrect array size"));
      }
      art::task4(argv[2], atoi(argv[3]));
    }
    else
    {
      throw(std::invalid_argument("Incorrect task number"));
    }
  }
  catch (std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }

  return 0;
}
