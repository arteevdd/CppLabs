#ifndef USER_INTERFACE_HPP
#define USER_INTERFACE_HPP

#include <map>

#include "phoneBook.hpp"
#include "util.hpp"

namespace arteev
{
  class UserInterface
  {
    public:
    using map_iter = std::map< std::string, const_iter >::iterator;
    UserInterface();
    void add(const record& rec);
    void store(const std::string& name, const std::string& newName);
    void deleteRecord(const std::string& markName);
    record show(const std::string& markName);
    void move(const std::string& markName, const std::string& steps);
    void insertNote(const std::string& mode, const std::string& markName, const record& rec);

    private:
    PhoneBook book;
    std::map< std::string, const_iter > bookmarks;

    void existBookmark(const std::string& name);
  };
}

#endif
