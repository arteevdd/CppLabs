#ifndef ACCESS_POLICIES_HPP
#define ACCESS_POLICIES_HPP

#include <vector>
#include <forward_list>

namespace arteev
{
  template< typename T >
  struct indexPolicy
  {
    using container = std::vector< T >;
    using iterator = size_t;

    static iterator begin(container&)
    {
      return 0;
    }

    static iterator end(container& cont)
    {
      return cont.size();
    }

    static T& get(container& cont, iterator& it)
    {
      return cont[it];
    }
  };

  template< typename T >
  struct atPolicy
  {
    using container = std::vector< T >;
    using iterator = size_t;

    static iterator begin(container&)
    {
      return 0;
    }

    static iterator end(container& cont)
    {
      return cont.size();
    }

    static T& get(container& cont, iterator& it)
    {
      return cont.at(it);
    }
  };

  template< typename T >
  struct iteratorPolicy
  {
    using container = std::forward_list< T >;
    using iterator = typename container::iterator;

    static iterator begin(container& cont)
    {
      return cont.begin();
    }

    static iterator end(container& cont)
    {
      return cont.end();
    }

    static T& get(container&, iterator& it)
    {
      return *it;
    }
  };
}

#endif
