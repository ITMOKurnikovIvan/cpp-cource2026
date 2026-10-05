#pragma once 

#include "Shape.h"

class Triangl: public Shape {
public:
    // конструкторы 
    Triangl();
    Triangl(const Triangl& other);
    Triangl(Triangl&& other) noexcept;
    Triangl(std::string type, double a, double b, double c);

    // деструктор
    ~Triangl();
    // операторы 
    Triangl& operator=(const Triangl& other);
    Triangl& operator=(Triangl&& other) noexcept;
    
    // сравнение 
    // bool operator==(const Triangl& other);
    // bool operator>(const Triangl& other) const;
    // bool operator<(const Triangl& other) const;
    // bool operator^(const)

    // вывод 
    friend std::ostream& operator<<(std::ostream& os,const Triangl& this_);

    // методы 
    double area() const override;
    double perimetr() const override;


private:
    double a, b, c;
    double phi, betta;
};
