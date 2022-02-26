#include "container.hpp"

namespace art = arteev;

art::Container::Iterator::Iterator():
  index_(1),
  value_(1)
{
}

art::Container::Iterator::Iterator(size_t index, size_t value):
  index_(index),
  value_(value)
{
}

art::Container::Iterator& art::Container::Iterator::operator++()
{
  assert(index_ < MAX_NUMBER + 1);
  ++index_;
  value_ *= index_;
  return *this;
}

art::Container::Iterator& art::Container::Iterator::operator--()
{
  assert(index_ != 1);
  value_ /= index_;
  --index_;
  return *this;
}

art::Container::Iterator art::Container::Iterator::operator--(int)
{
  Iterator temp = *this;
  --(*this);
  return temp;
}

art::Container::Iterator art::Container::Iterator::operator++(int)
{
  Iterator temp = *this;
  ++(*this);
  return temp;
}

const size_t& art::Container::Iterator::operator*() const
{
  return value_;
}

const size_t* art::Container::Iterator::operator->() const
{
  return std::addressof(value_);
}

bool art::Container::Iterator::operator==(const Iterator& it) const
{
  return index_ == it.index_;
}

bool art::Container::Iterator::operator!=(const Iterator& it) const
{
  return index_ != it.index_;
}


art::Container::Iterator art::Container::begin() const noexcept
{
  return Iterator(1, 1);
}

art::Container::Iterator art::Container::end() const noexcept
{
  return Iterator(MAX_NUMBER + 1, art::getFactorial(MAX_NUMBER + 1));
}
