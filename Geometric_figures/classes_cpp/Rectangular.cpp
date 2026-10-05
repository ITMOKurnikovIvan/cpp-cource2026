#include "../include_h/Rectangular.h"
#include <stdexcept>
#include <string>
#include <utility>
#include <iostream>
#include <cmath>

// конструкторы 
Rectangular::Rectangular(): Shape("Rectangular"), a(0), b(0){}
Rectangular::Rectangular(const Rectangular& other):
    Shape(other.name),
    a(other.a),
    b(other.b){}

Rectangular::Rectangular(Rectangular&& other) noexcept: 
    Shape(std::move(other.name)),
    a(other.a),
    b(other.b){}

Rectangular::Rectangular(double a, double b): Shape("Rectangular"), a(a), b(b){
    if(a <= 0 || b <= 0 ){
        throw std::invalid_argument("невозможная фигура");
    }
}

// деструкторы
Rectangular::~Rectangular() = default;

// операторы 
Rectangular& Rectangular::operator=(const Rectangular& other){
    if(this != &other){
        name = other.name;
        a = other.a;
        b = other.b;
    }
    return *this;
}

Rectangular& Rectangular::operator=(Rectangular&& other) noexcept {
    if(this != &other){
        name = std::move(other.name);
        a = other.a;
        b = other.b;
        other.b = 0;
        other.a = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Rectangular& this_){
    return os << this_.name << "sides    (" << this_.a <<
     ", " << this_.b << ")\n";
}

// методы 
double Rectangular::area() const {
    return a * b;
}
double Rectangular::perimetr() const {
    return 2 * a + 2 * b;
}