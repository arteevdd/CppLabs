#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>

#include "record.hpp"

namespace arteev
{
  using const_iter = std::list< record >::const_iterator;
  using iter = std::list< record >::iterator;

  class PhoneBook
  {
  public:
    record showCurrent();
    void next();
    void pred();
    void insertBefore(const_iter it, const record& rec);
    void insertAfter(const_iter it, const record& rec);
    void replace(iter it, const record& rec);
    void pushBack(const record& rec);
    const_iter move(const_iter it, int steps);

    const_iter delet(const_iter it);

    const_iter begin() const;
    const_iter end() const;

    int size() const;

  private:
    std::list< record > records_;
    const_iter currentRecord_;
  };
}

#endif
