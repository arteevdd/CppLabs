#include <iostream>
#include "circle.hpp"
#include "rectangle.hpp"

void printFrameRect(const Shape* s)
{
  rectangle_t reserve = s->getFrameRect();
  std::cout << "\nCoordinates: " << "X = " << reserve.pos.x
  << "; Y = " << reserve.pos.y << '\n';
  std::cout << "Height and width: ";
  std::cout << "h = " << reserve.height <<
  "; w = " << reserve.width << '\n';
}

void printArea(const Shape *s)
{
  std::cout << "\nArea: " << s->getArea() << '\n';
}

void testMove(Shape* s, double dx, double dy)
{
  std::cout << "Parameters before move: ";
  printFrameRect(s);
  std::cout << "\nParameters after move: ";
  s->move(dx, dy);
  printFrameRect(s);
  std::cout << '\n'<<'\n';
}

void testMove(Shape* s, point_t position)
{
  std::cout << "Parameters before move: ";
  printFrameRect(s);
  std::cout << "\nParameters after move: ";
  s->move(position);
  printFrameRect(s);
  std::cout << '\n' << '\n';
}

int main()
{
  Shape* figureCircle = new Circle({ 2, 2 }, 3);

  point_t pos = { 12, 7 };

  testMove(figureCircle, pos);

  testMove(figureCircle, 3, 2);

  printArea(figureCircle);

  delete figureCircle;

  pos = { 5, 8 };

  Shape* figureRectangle = new Rectangle(10, 12, { 5, 5 });

  testMove(figureRectangle, 10, 65);

  testMove(figureRectangle, pos);

  printArea(figureRectangle);

  delete figureRectangle;
}
