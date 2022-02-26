#include "counter.hpp"
#include "utils.hpp"
#include "shape.hpp"
#include "tasks.hpp"
#include <iostream>
#include <iterator>
#include <algorithm>

namespace art = arteev;

void art::task2(std::istream& in, std::ostream& out)
{
  std::istream_iterator< Shape > begin(in);
  std::istream_iterator< Shape > end;
  std::vector< Shape > shapes(begin, end);
  if (in.fail() && !in.eof())
  {
    throw (std::runtime_error("Inavalid input"));
  }

  Counter count = std::for_each(shapes.begin(), shapes.end(), Counter());

  shapes.erase(std::remove_if(shapes.begin(), shapes.end(), isPentagon), shapes.end());

  std::vector< Point > points;
  std::transform(shapes.begin(), shapes.end(), std::back_inserter(points), getPeak);

  std::sort(shapes.begin(), shapes.end());

  out << count;

  out << "Points: ";
  std::copy(points.cbegin(), points.cend(), std::ostream_iterator< Point >(out, " "));
  out << "\nShapes:\n";
  std::copy(shapes.cbegin(), shapes.cend(), std::ostream_iterator< Shape >(out, "\n"));
}
