#include "tasks.hpp"
#include "userInterface.hpp"

#include <sstream>

namespace art = arteev;

void art::task1(std::istream& in, std::ostream& out)
{
  art::UserInterface UI;
  std::string command;

  while (std::getline(in, command) && !command.empty())
  {
    try
    {
      std::istringstream stream(command);
      std::string action = read(stream);
      if (action == "add")
      {
        std::string number = read(stream);
        if (!checkDigits(number, false)) 
        {
          throw std::invalid_argument("<INVALID COMMAND>");
        }
        std::string name = readName(stream);
        UI.add({ name, number });
      }
      else if (action == "store")
      {
         std::string oldMarkName = read(stream);
         std::string newMarkName = read(stream);
         if (!checkMarkName(oldMarkName) || !checkMarkName(newMarkName))
         {
           throw std::invalid_argument("<INVALID BOOKMARK>");
         }
         UI.store(oldMarkName, newMarkName);
      }
      else if (action == "insert")
      {
        std::string mode = read(stream);
        if (!checkInsertMode(mode))
        {
          throw std::invalid_argument("<INVALID COMMAND>");
        }
        std::string markName = read(stream);
        if (!checkMarkName(markName))
        {
          throw std::invalid_argument("<INVALID BOOKMARK>");
        }
        std::string number = read(stream);;
        if (!checkDigits(number, false))
        {
          throw std::invalid_argument("<INVALID COMMAND>");
        }
        std::string name = readName(stream);
        if (mode == "after") 
        {
          UI.insertNote("after", markName, { name, number });
        }
        else
        {
          UI.insertNote("before",markName, { name, number });
        }
      }
      else if (action == "delete")
      {
        std::string markName = read(stream);
        if (!checkMarkName(markName))
        {
          throw std::invalid_argument("<INVALID BOOKMARK>");
        }
        UI.deleteRecord(markName);
      }
      else if (action == "show")
      {
        std::string markName = read(stream);
        if (!checkMarkName(markName))
        {
          throw std::invalid_argument("<INVALID BOOKMARK>");
        }
        out << UI.show(markName) << '\n';
      }
      else if (action == "move")
      {
        std::string markName = read(stream);
        checkMarkName(markName);
        std::string steps = read(stream);
        if (checkSteps(steps))
        {
          UI.move(markName, steps);
        }
        else
        {
          throw std::invalid_argument("<INVALID STEP>");
        }
      }
      else
      {
        throw std::invalid_argument("<INVALID COMMAND>");
      }
    }
    catch (const std::invalid_argument& e)
    {
      out << e.what() << "\n";
    }
  }
}