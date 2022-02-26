#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>
#include <cassert>

#include "util.hpp"

constexpr size_t MAX_NUMBER = 10;

namespace arteev
{
  class Container
  {
  public:
    class Iterator: public std::iterator< std::bidirectional_iterator_tag, size_t >
    {
    public:
      Iterator();

      Iterator& operator++();
      Iterator& operator--();

      Iterator operator--(int);
      Iterator operator++(int);

      const size_t& operator*() const;
      const size_t* operator->() const;

      bool operator==(const Iterator& it) const;
      bool operator!=(const Iterator& it) const;

      private:
      size_t index_;
      size_t value_;

      Iterator(size_t index, size_t value);
      friend class Container;
    };

    Iterator begin() const noexcept;
    Iterator end() const noexcept;

  };
}

#endif
