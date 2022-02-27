#include <stdexcept>
#include <iostream>
#include <string>
#include <cstring>
#include "tasks.hpp"

namespace art = arteev;

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 2)
    {
      throw(std::invalid_argument("Incorrect count of arguments"));
    }

    if (std::strlen(argv[1]) != 1)
    {
      throw(std::invalid_argument("Incorrect task number"));
    }

    int taskNumber = std::stoi(argv[1]);
    if ((taskNumber != 1) && (taskNumber != 2))
    {
      throw(std::invalid_argument("Incorrect task number"));
    }

    if (taskNumber == 1)
    {
      art::task1(std::cin, std::cout);
    }
    else if (taskNumber == 2)
    {
      art::task2(std::cin, std::cout);
    }
  }
  catch (std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
}
