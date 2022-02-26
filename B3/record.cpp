#include "record.hpp"

std::ostream& arteev::operator<<(std::ostream& out, const record& rec)
{
  out << rec.phone << " " << rec.name;
  return out;
}
