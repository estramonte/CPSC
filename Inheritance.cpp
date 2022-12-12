#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape
{

public:
  Shapte(double dHeight, double dWidth);
  virtual ~Shape();
  virtual void scale(double dScaleFactor) = 0;
  virtual double area() = 0;
  virtual double perimeter() = 0;
  virtual void displayProperties();

protected:
  double m_dHeight;
  double m_dWidth;
  string m_strType;
};

class Rectangle : public Shape
{
public:
  Rectangle(double dHeight, double dWidth);
  virtual ~Rectangle();
  void scale (double dScaleFactor);
  double area();
  double perimeter();
};

class Circle : public Shape
{
public:
  Circle(double dHeight, double dWidth);
  virtual ~Circle();
  void scale (double dScaleFactor);
  double area();
  double perimeter();
};

int main()
{
  Rectangle* p_shapeRectangle = new Rectangle (2.0,3.0);
  Circle* p_shapeCircle = new Circle(2.0,2.0);

  Shape* p_shapes[2];

  p_shapes[0] = p_shapeCircle;
  p_shapes[1] = p_shapeRectangle;

  double dArea = p_shapes[i] -> area();
}
