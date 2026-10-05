#include "../include_h/Square.h"
#include <stdexcept>
#include <string>
#include <utility>
#include <iostream>
#include <cmath>

// конструкторы 
Square::Square(): Rectangular() { name = "Square"; }
Square::Square(const Square& other): Rectangular(other) {
    name = "Square";
}

Square::Square(Square&& other) noexcept: 
Rectangular(std::move(other)){
    name = "Square";
}

Square::Square(double a): Rectangular(a, a) {
    name = "Square";
    if(a <= 0){
        throw std::invalid_argument("невозможная фигура");
    }
}

// деструкторы
//Square::~Square() = default;

// операторы 
Square& Square::operator=(const Square& other){
    if(this != &other){
        name = other.name;
        a = other.a;
        b = other.b;
    }
    return *this;
}

Square& Square::operator=(Square&& other) noexcept {
    if(this != &other){
        name = std::move(other.name);
        a = other.a;
        b = other.b;
        other.b = 0;
        other.a = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Square& this_){
    return os << this_.name << "side ( " << this_.a << " )\n";
}

