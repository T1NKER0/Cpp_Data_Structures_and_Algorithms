#include <cmath>

class Circle
{
public:
Circle(); //constructor
double getCircleArea(); //return area
double getCircumference(); //return circumference
void setRadius(double rad); //set radius

private:
double radius;
};

//constructor
Circle :: Circle()
{
  radius = 0;
}


void Circle :: setRadius(double rad)
{
  radius = rad;
}

double Circle :: getCircleArea ()
{
  return 3.14 * pow(radius, 2);
}

double Circle :: getCircumference()
{
  return 2 * 3.14 * radius;
}
