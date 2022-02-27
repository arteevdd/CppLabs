#include "utils.hpp"
#include <stdexcept>

bool arteev::checkNumber(const char* string)
{
  for (size_t i = 0; i < strlen(string); i++)
  {
    if (!isdigit(string[i]))
    {
      return false;
    }
  }
  return true;
}

void arteev::fillRand(double* array, int size)
{
  if (size <= 0)
  {
    throw (std::invalid_argument("Invalid array size"));
  }
   for (int i = 0; i < size; i++)
  {
    array[i] = rand() / (RAND_MAX * 1.0) * 2 - 1;
  }
}
