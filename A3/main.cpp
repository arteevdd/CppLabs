#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"
#include "composite-shape.hpp"

namespace art = arteev;

namespace arteev
{
  void printInfo(std::ostream& out, art::Shape::UniquePtr& shape)
  {
    out << "Shape: " << shape->getName() << "\n";
    out << "Coordinates: {" << getX(shape) << ", " << getY(shape) << "};\n";
    out << "Width of frame " << shape->getName() << ": " << getWidth(shape) << ";\n";
    out << "Height of frame " << shape->getName() << ": " << getHeight(shape) << ";\n";
    out << "Area of the limiting figure: " << getWidth(shape) * getHeight(shape) << ";\n\n";
  };

  void printCoordinates(std::ostream& out, art::Shape::UniquePtr& shape)
  {
    out <<"{" << getX(shape) << ", " << getY(shape) << "};";
  };

  void printParameters(std::ostream& out, art::Shape::UniquePtr& shape, const double k)
  {
    out << "Width and height before " << shape->getName() << " scale: "
    << getWidth(shape) / k << ", " << getHeight(shape) / k << ";\n";
    out << "Width of frame " << shape->getName() << ": " << getWidth(shape) << ";\n";
    out << "Height of frame " << shape->getName() << ": " << getHeight(shape) << ";\n";
    out << "Area of the limiting figure: " << getWidth(shape) * getHeight(shape) << ";\n";
  }

  void testMove(std::ostream& out, art::Shape::UniquePtr& shape, double dx, double dy, point_t pos)
  {
    out <<":\nCoordinates before move: ";
    art::printCoordinates(std::cout, shape);
    out <<"\n";
    out <<"Coordinates after move (method dx, dy): ";
    shape->move(dx, dy);
    art::printCoordinates(std::cout, shape);
    out <<"\nCoordinates after move (method pos_ = pos): ";
    shape->move(pos);
    art::printCoordinates(std::cout, shape);
    out <<"\n";
  };
}

int main()
{
  const double dx = 4;
  const double dy = 12;
  const int size = 2;
  const double k = 5;
  const art::point_t pos = {0, 0};

  art::CompositeShape::UniqueShape shapes = std::make_unique< art::Shape::UniquePtr[] >(size);
  shapes[0] = std::make_unique< art::Rectangle >(art::Rectangle(6, 8, {1, 2}));
  shapes[1] = std::make_unique< art::Circle >(art::Circle(3, {6, 1}));

  std::cout << "\nChecking the shape information: \n\n";
  for (int i = 0; i < size; i++)
  {
    art::printInfo(std::cout, shapes[i]);
  }

  std::cout << "\nTest move: \n\n";
  for (int i = 0; i < size; i++)
  {
    std::cout << shapes[i]->getName();
    testMove(std::cout, shapes[i], dx, dy, pos);
    std::cout << "\n";
  }

  std::cout << "\nTest scale: \n\n";
  for (int i = 0; i < size; i++)
  {
    shapes[i]->scale(k);
    printParameters(std::cout, shapes[i], k);
    std::cout << "\n";
  }

  return 0;
}

