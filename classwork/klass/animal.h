#pragma once 
#include <string>

class Animal{
public:
    int age;
    std::string sound;
    std::string name;
    std::string eat;
    std::string territoria;

    Animal(){
        age = 0;
        sound = "ZZZ__ZZ_Z___";
        name = "noname";
        eat = "void";
        territoria = "everywhere";   
    }

    Animal(int a,
    std::string s,
    std::string n,
    std::string e,
    std::string t): age(a), sound(s), name(n), 
    eat(e), territoria(t){}

    Animal(const Animal& other) = default; // копирует 
protected:
        ~Animal() = default;



};