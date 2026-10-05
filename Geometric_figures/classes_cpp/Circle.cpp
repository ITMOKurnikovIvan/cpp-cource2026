#include "../include_h/Circle.h"
#include <stdexcept>
#include <string>
#include <utility>
#include <iostream>
#include <cmath>

Circle::Circle(): Shape("Circle"), R(0){}
Circle::Circle(const Circle& other): Shape(other.name), R(other.R){}
Circle::Circle(Circle&& other) noexcept {
    name = std::move(other.name);
    R = other.R;

    other.R = 0;
    other.name = "";

}
Circle::Circle(double R): Shape("Circle"), R(R){
    if(R <= 0){
        throw std::invalid_argument("радиус должен быть положительным");
    }
}

// деструктор
Circle::~Circle() = default;

// операторы 
Circle& Circle::operator=(const Circle& other){
    if(this != &other){
        name = other.name;
        R = other.R;
    }
    return *this;    
}
Circle& Circle::operator=(Circle&& other) noexcept {
    if(this != &other){
        name = other.name;
        R = other.R;

        other.R = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Circle& this_){
    if(this_.R > 0){
        return os << this_.getName() << "Radius = " << this_.R << std::endl;
    }
    else {
        return os << this_.getName() << " неизвестен, все характеристики не определены " << std::endl;
    }
}

double Circle::area() const {
    return M_PI * R * R;
}
double Circle::perimetr() const {
    return 2 * M_PI * R;
}
