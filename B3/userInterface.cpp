#include "userInterface.hpp"

namespace art = arteev;

art::UserInterface::UserInterface():
  book(PhoneBook()),
  bookmarks({std::make_pair("current", book.begin())})
{
}

void art::UserInterface::add(const record& rec)
{
  book.pushBack(rec);
  if (book.size() == 1)
  {
    bookmarks["current"] = book.begin();
  }
}

void art::UserInterface::store(const std::string& name, const std::string& newName)
{
  existBookmark(name);
  bookmarks[newName] = bookmarks[name];
}

void art::UserInterface::existBookmark(const std::string& name)
{
  if (bookmarks.find(name) == bookmarks.end())
  {
    throw (std::invalid_argument("<INVALID BOOKMARK>"));
  }
}

void art::UserInterface::insertNote(const std::string& mode, const std::string& markName, const record& rec)
{
  if (book.size() == 0)
  {
    add(rec);
    return;
  }
  if (mode == "before")
  {
    book.insertBefore(bookmarks.find(markName)->second, rec);
  }
  else if (mode == "after")
  {
    book.insertAfter(bookmarks.find(markName)->second, rec);
  }
}

void art::UserInterface::deleteRecord(const std::string& markName)
{
  existBookmark(markName);
  art::const_iter oldValue = bookmarks[markName];
  art::const_iter newValue = book.delet(bookmarks[markName]);
  if (newValue == book.end())
  {
    newValue = book.begin();
  }
  for (map_iter i = bookmarks.begin(); i != bookmarks.end(); i++)
  {
    if (i->second == oldValue)
    {
      i->second = newValue;
    }
  }
}

art::record art::UserInterface::show(const std::string& markName)
{
  existBookmark(markName);
  if (book.size() == 0)
  {
    throw std::invalid_argument("<EMPTY>");
  }

  return *(bookmarks[markName]);
}

void art::UserInterface::move(const std::string& markName, const std::string& steps)
{
  existBookmark(markName);
  if (!checkSteps(steps))
  {
    throw std::invalid_argument("INVALID STEP");
  }

  if (steps == "last")
  {
    bookmarks[markName] = --book.end();
  }
  else if (steps == "first")
  {
    bookmarks[markName] = book.begin();
  }
  else
  {
    bookmarks[markName] = book.move(bookmarks[markName], std::stoi(steps));
  }
}
