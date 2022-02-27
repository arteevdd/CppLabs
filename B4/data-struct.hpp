#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <iostream>

namespace arteev
{
  struct DataStruct
  {
    int key1;
    int key2;
    std::string str;
  };

  bool operator<(const DataStruct& lhs, const DataStruct& rhs);
  std::istream& operator>>(std::istream& in, DataStruct& dataStruct);
  std::ostream& operator<<(std::ostream& out, const DataStruct& dataStruct);
  int getKey(std::istream& in);
}

#endif