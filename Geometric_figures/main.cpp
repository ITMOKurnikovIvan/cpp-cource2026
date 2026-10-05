#include "Circle.h"
#include "Rectangular.h"
#include "Square.h"
#include "Triangl.h"
#include <iostream>

int main() {
    // Circle
    Circle c( 5.0);
    std::cout << "Circle:  area = " << c.area()
              << ", perimetr = " << c.perimetr() << "\n";

    // Rectangular
    Rectangular r(3.0, 4.0);
    std::cout << "Rect:    area = " << r.area()
              << ", perimetr = " << r.perimetr() << "\n";

    // Square
    Square s( 5.0);
    std::cout << "Square:  area = " << s.area()
              << ", perimetr = " << s.perimetr() << "\n";

    // Triangle через 3 стороны
    Triangl t("3side", 3.0, 4.0, 5.0);
    std::cout << "Triangle: area = " << t.area()
              << ", perimetr = " << t.perimetr() << "\n";

    return 0;
}