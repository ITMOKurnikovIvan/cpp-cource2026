#pragma once 

#include "Shape.h"

class Rectangular: public Shape {
public:
    // Конструкторы 
    Rectangular();
    Rectangular(const Rectangular& other);
    Rectangular( Rectangular&& other) noexcept;
    Rectangular(double a, double b);
    // деструкторы 
    ~Rectangular();
    // операторы 
    Rectangular& operator=(const Rectangular& other);
    Rectangular& operator=(Rectangular&& other) noexcept;
    friend std::ostream& operator<<(std::ostream& os,const Rectangular& this_);
    // методы 
    double area() const override;
    double perimetr() const override;
    
protected:
    double a, b;
};
