// overloading class constructors
#include <iostream>

// Rectangle class
class Rectangle {
    int width, height; // attributes
  public:
    Rectangle (); // methods
    Rectangle (int,int);
    int area (void) {return (width*height);}
};

// Base constructor
Rectangle::Rectangle () {
  width = 5;
  height = 5;
}

// Overriden constructor
Rectangle::Rectangle (int a, int b) {
  width = a;
  height = b;
}

int main () {
  Rectangle rect (3,4);
  Rectangle * rectb = &rect;
  std::cout << "rect area: " << rect.area() << std::endl;
  std::cout << "rectb area: " << rectb->area() << std::endl; // Pointers to classes
  return 0;
}
