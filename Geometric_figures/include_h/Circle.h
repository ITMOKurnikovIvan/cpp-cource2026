#pragma once 
#include "Shape.h"

class Circle: public Shape{
public:
    // конструкторы 
    Circle();
    Circle(const Circle& other);
    Circle(Circle&& other) noexcept ;
    Circle(double R);


    //деструктор
    ~Circle();

    // оператор
    Circle& operator=(const Circle& other);
    Circle& operator=(Circle&& other) noexcept ;

    friend std::ostream& operator<<(std::ostream& os, const Circle& this_);
    // методы
    double area() const override;
    double perimetr() const override;

private:
    double R;

};
