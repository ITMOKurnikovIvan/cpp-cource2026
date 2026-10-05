#pragma once 
#include "Shape.h"
#include "Rectangular.h"

class  Square: public Rectangular {
public:
    Square();
    Square(const Square& other);
    Square(Square&& other) noexcept;
    Square(double a);

    //~Square();

    Square& operator=(const Square& other);
    Square& operator=(Square&& other) noexcept;
    
    friend std::ostream& operator<<(std::ostream& os, const Square& this_);


};
