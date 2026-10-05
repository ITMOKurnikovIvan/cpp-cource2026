#include "../include_h/Triangl.h"
#include <stdexcept>
#include <string>
#include <utility>
#include <iostream>
#include <cmath>


Triangl::Triangl(): Shape("triangle"), a(0), b(0), c(0) {}
Triangl::Triangl(const Triangl& other): 
    Shape(other.name),
    a(other.a),
    b(other.b),
    c(other.c) {}
    
Triangl::Triangl( Triangl&& other) noexcept:
    Shape(std::move(other.name)),
    a(other.a),
    b(other.b),
    c(other.c) {}

Triangl::Triangl(std::string type, double x1, double x2, double x3)
{
    this -> name = "triangle";

    if(type == "2angle_1side"){
        if(x2 + x1 < M_PI && x3 > 0)
            {phi = x1;
            betta = x2;
            this -> a = x3;
            this -> b = 0;
            this -> c = 0;}
    
        else {
            throw std::invalid_argument("треугольника не существует , углы в сумме 180");
        }
    }

    if(type == "1angle_2side"){
        if( x1 < M_PI && x2 > 0 && x3 > 0){
            phi = x1;
            betta = 0;
            this -> a = x2;
            this -> b = x3;
            this -> c = 0;
        }
            else {
            throw std::invalid_argument("треугольника не существует , углы в сумме 180");
        } 
    }

    if(type == "3side"){
        if(x1 > 0 && x2 > 0 && x3 > 0 && x1 + x2 > x3 && x1 + x3 > x2 && x2 + x3 > x1){
            phi = 0;
            betta = 0;
            this -> a = x1;
            this -> b = x2;
            this -> c = x3;
        }
        else {
            throw std::invalid_argument("треугольника не существует , каждая сторона меньше двух других и не равна нулю");
        } 
    }
}

// деструктор
Triangl::~Triangl() = default;

// операторы 
Triangl& Triangl::operator=(const Triangl& other){
    if(this != &other){
        name = other.name;
        a = other.a;
        b = other.b;
        c = other.c;
        phi = other.phi;
        betta = other.betta;
    }
    return *this;
}

Triangl& Triangl::operator=(Triangl&& other) noexcept {
    if(this != &other){
        name = std::move(other.name);
        a = other.a;
        b = other.b;
        c = other.c;
        phi = other.phi;
        betta = other.betta;

        other.a = 0;
        other.b = 0;
        other.c = 0;
        other.phi = 0;
        other.betta = 0;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& os,const Triangl& this_){
    return os << this_.getName() << "side (" << this_.a << ", " << this_.b <<
     ", " << this_.c << ")\n" << "angl (" << this_.phi << ", " << this_.betta <<
     ")\n";
}

// площадь
double Triangl::area() const {
    if(a != 0 && b != 0 && c != 0){
        double perimetr2 = (a + b + c) / 2.0;
        return std::sqrt(perimetr2 * (perimetr2 - a) *
        (perimetr2 - b) * (perimetr2 - c));
    }

    if(phi != 0 && a != 0 && b != 0){
        return std::sin(phi) * a * b / 2.0 ;
    }

    if(phi != 0 && betta != 0 && a != 0){
        double b_new = (a * std::sin(betta)) / std::sin(M_PI - phi - betta);
        double c_new = (a * std::sin(phi)) / std::sin(M_PI - phi - betta);
        double perimetr2_new = (a + b_new + c_new) / 2.0;

        return std::sqrt(perimetr2_new * (perimetr2_new - a) *
        (perimetr2_new - b_new) * (perimetr2_new - c_new));
    }
    return 0;
}
// периметр
double Triangl::perimetr() const {

    if(a != 0 && b != 0 && c != 0){
        return a + b + c;  
    }
    if(phi != 0 && a != 0 && b != 0){
        double c_new = std::sqrt(a * a + b * b - 2 * a * b * std::cos(phi));
        return a + b + c_new;
    }
    if(phi != 0 && betta != 0 && a != 0){
        double b_new = (a * std::sin(betta)) / std::sin(M_PI - phi - betta);
        double c_new = (a * std::sin(phi)) / std::sin(M_PI - phi - betta);

        return a + b_new + c_new;
    }
    return 0;
}
