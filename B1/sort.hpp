#ifndef SORT_HPP
#define SORT_HPP

#include <functional>
#include <utility>

template< typename T, template<typename> typename AccessPolicy >
void selection_sort(typename AccessPolicy< T >::container& cnt, const std::function< bool(const T&, const T&) >& cmp)
{
    using policy = AccessPolicy< T >;
    using container = typename AccessPolicy< T >::container;
    using iterator = typename AccessPolicy< T >::iterator;

    container tmp(cnt);
    iterator first = policy::begin(tmp);
    iterator last = policy::end(tmp);

    while (first != last)
    {
      iterator min = first;
      iterator it = first;

      while (++it != last)
      {
        if (!cmp(policy::get(tmp, min), policy::get(tmp, it)))
        {
          min = it;
        }
      }
      std::swap(policy::get(tmp, first), policy::get(tmp, min));
      ++first;
    }
    std::swap(cnt, tmp);
}

#endif
