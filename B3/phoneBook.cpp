#include "phoneBook.hpp"

namespace art = arteev;

art::record art::PhoneBook::showCurrent()
{
  return *currentRecord_;
}

void art::PhoneBook::next()
{
  if (currentRecord_ != end())
  {
    currentRecord_++;
  }
}

void art::PhoneBook::pred()
{
  if (currentRecord_ != begin())
  {
    currentRecord_--;
  }
}

void art::PhoneBook::insertBefore(const_iter it, const record& rec)
{
  records_.insert(it, rec);
}

void art::PhoneBook::insertAfter(const_iter it, const record& rec)
{
  records_.insert(++it, rec);
}

void art::PhoneBook::replace(iter it, const record& rec)
{
  *it = rec;
}

void art::PhoneBook::pushBack(const record& rec)
{
  records_.push_back(rec);
}

art::const_iter art::PhoneBook::move(const_iter it, int steps)
{
  if (steps < 0)
  {
    while (it != begin() && steps != 0)
    {
      --it;
      ++steps;
    }
  }
  else
  {
    auto end_it = --end();
    while (it != end_it && steps != 0)
    {
      ++it;
      --steps;
    }
  }
   return it;
}

art::const_iter art::PhoneBook::delet(const_iter it)
{
  return records_.erase(it);
}

art::const_iter art::PhoneBook::begin() const
{
  return records_.cbegin();
}

art::const_iter art::PhoneBook::end() const
{
  return records_.cend();
}

int art::PhoneBook::size() const
{
  return records_.size();
}
