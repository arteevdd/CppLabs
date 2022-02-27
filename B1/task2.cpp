#include "tasks.hpp"
#include "utils.hpp"

#include <fstream>
#include <stdexcept>
#include <memory>
#include <vector>

void arteev::task2(const char* fileName)
{
  if (!fileName)
  {
    throw (std::invalid_argument("Incorrect file name"));
  }
  std::ifstream file(fileName);
  if (!file)
  {
    throw (std::runtime_error("File open error"));
  }

  int capacity = 100;
  int size = 0;
  std::unique_ptr< char[] > arr = std::make_unique< char[] >(capacity);

  while (!file.eof())
  {
    file.read(arr.get() + size, capacity - size);
    size += file.gcount();
    capacity *= 2;
    std::unique_ptr< char[] > temp = std::make_unique< char[] >(capacity);
    for (int i = 0; i < size; i++)
    {
      temp[i] = arr[i];
    }
    arr = std::move(temp);
  }

  file.close();
  std::vector< char > vec(arr.get(), arr.get() + size);
  for (int i = 0; i < size; i++)
  {
    std::cout << vec[i];
  }
}
