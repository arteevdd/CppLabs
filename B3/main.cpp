#include <iostream>

#include "userInterface.hpp"
#include "util.hpp"
#include "tasks.hpp"

int main(int argc, char* argv[])
{
  int returnCode = 0;
  try
  {
    if (argc != 2)
    {
      throw std::invalid_argument("<Invalid number of arguments>");
    }
    if (arteev::checkDigits(argv[1]))
    {
      int taskNumber = std::atoi(argv[1]);
      if (taskNumber == 1)
      {
        arteev::task1(std::cin, std::cout);
      }
      else if (taskNumber == 2)
      {
        arteev::task2(std::cout);
      }
      else
      {
        throw std::invalid_argument("<Invalid TaskNumber>");
      }
    }
    else
    {
      throw std::invalid_argument("<Invalid Args>");
    }
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
    returnCode = 1;
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << "\n";
    returnCode = 2;
  }
  return returnCode;
}
