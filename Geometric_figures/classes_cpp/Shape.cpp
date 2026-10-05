#include "Shape.h"
#include <stdexcept>
#include <string>
#include <utility>
#include <iostream>
#include <cmath>

// конструкторы 
Shape::Shape(): name("noname") {}
Shape::Shape(const Shape& other): name(other.name) {}
Shape::Shape(Shape&& other) noexcept: name(std::move(other.name))  {}
Shape::Shape(string name_): name(name_) {}

// деструкторы 
Shape::~Shape() = default;

// операторы 
Shape& Shape::operator=(const Shape& other){
    if(this != &other) name = other.name;
    return *this;
}
Shape& Shape::operator=(Shape&& other) noexcept {
    if(this != &other) this -> name = std::move(other.name);
    return *this;
}
// сравнения 
bool Shape::operator==(const Shape& other) const {
    return std::abs( this -> area() - other.area()) < 1e-9;
}
bool Shape::operator!=(const Shape& other) const {
    return !(*this == other);
}
bool Shape::operator>(const Shape& other) const {
    if(other != *this) return this -> area() > other.area();
    return 0;
} 
bool Shape::operator<(const Shape& other)const {
    return !(*this > other || *this == other);
}
bool Shape::operator^(const Shape& other) const{
    return std::abs( this -> perimetr() - other.perimetr()) < 1e-9;
}

// функции 
// bool Shape::equal_ravenstvo_area(const Shape& other) const {
//     return std::abs(this -> area() - other.area()) < 1e-9;
// }
// bool Shape::equal_ravenstvo_perimetr(const Shape& other) const {
//     return std::abs(this -> perimetr() - other.perimetr()) < 1e-9;
// }
// bool Shape::equal_bolse_area(const Shape& other) const {
//     if(other == *this) return this -> area() > other.area();
//     return 0;
// }

// методы 
string Shape::getName() const {
    return this -> name;
}
// вывода оператор
std::ostream& operator<<(std::ostream& os, const Shape& this_) {
    return os << "name Shape is" << this_.name << std::endl;
}