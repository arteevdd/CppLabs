#ifndef RECORD_HPP
#define RECORD_HPP

#include <string>
#include <iostream>

namespace arteev
{
  struct record
  {
    std::string name;
    std::string phone;
  };

  std::ostream& operator<<(std::ostream& out, const record& rec);
}

#endif
