class Rectangle 
{
public: 
Rectangle ();
void setLength(double length);
void setWidth(double width);
double getRectangleArea();
double getRectanglePerimeter();

private:
double length;
double width;
};

Rectangle :: Rectangle()
{
  length = width = 0;
}

void Rectangle :: setLength(double l)
{
  length = l;
}

void Rectangle :: setWidth(double w)
{
  width = w;
}

double Rectangle :: getRectangleArea()
{
  return length * width;
}

double Rectangle :: getRectanglePerimeter()
{
  return 2 * length + 2 * width;
}
