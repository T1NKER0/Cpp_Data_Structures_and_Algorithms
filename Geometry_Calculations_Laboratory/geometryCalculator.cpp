#include <iostream>
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;

//function prototypes:
void printMenu(); //displays menu

int main()
{
  int selection;
  double radius, length, width, base, height, side1, side2, side3;
  
  //boot up menu
  printMenu();

  //enter selection
  cin >> selection;

  if (selection < 1 && selection > 6)
  {
    cout <<"Enter a valid number (1 - 6)!";
  }

  switch (selection)
    {
      case 1:
        {
          cout <<"Enter the radius: ";
          cin >> radius;

          Circle circleObj;
          circleObj.setRadius(radius);

          cout <<"Circle Area: " <<circleObj.getCircleArea() <<endl;
        }
        break;

      case 2:
        {
          cout <<"Enter Length: ";
          cin >> length;

          cout <<"Enter Width: ";
          cin >> width;

          Rectangle rectangleObj;
          rectangleObj.setLength(length);
          rectangleObj.setWidth(width);

          cout <<"Rectangle Area: "       <<rectangleObj.getRectangleArea() <<endl;
        }
      break;

      case 3:
        {
          cout <<"Enter base: ";
          cin >> base;

          cout <<"Enter height: ";
          cin >> height;

          Triangle triangleObj;
          triangleObj.setTriangleBase(base);
          triangleObj.setTriangleHeight(height);

          cout <<"Triangle Area :" <<triangleObj.getTriangleArea() <<endl;
        }
        break;
      
      case 4: 
        {
           cout <<"Enter the radius: ";
          cin >> radius;

           Circle circleObj;
          circleObj.setRadius(radius);

          cout <<"Circumference: " <<circleObj.getCircumference() <<endl;
        }
      break;

      case 5: 
        {
            cout <<"Enter Length: ";
          cin >> length;

          cout <<"Enter Width: ";
          cin >> width;

          Rectangle rectangleObj;
          rectangleObj.setLength(length);
          rectangleObj.setWidth(width);

          cout <<"Rectangle Perimeter: "       <<rectangleObj.getRectanglePerimeter() <<endl;
        }
      break;

      case 6: 
        {
          cout <<"Enter side 1: ";
          cin >> side1;
          cout <<"Enter side 2: ";
          cin >> side2;
          cout <<"Enter side 3: ";
          cin >> side3;

           Triangle triangleObj;
          triangleObj.setTriangleSides(side1, side2, side3);

          cout <<"Triangle Perimeter: " <<triangleObj.getTrianglePerimeter() <<endl;
        }

        }
    }
    
    void printMenu()
{
  cout <<"-----Geometry Calculator---- \n" <<"Select An Option: \n";
  cout <<"1. Circle Area \n";
  cout <<"2. Rectangle Area \n";
  cout <<"3. Triangle Area \n";
  cout <<"4. Circle Circumference \n";
  cout <<"5. Rectangle Perimeter \n";
  cout <<"6. Triangle Perimeter \n";
}
