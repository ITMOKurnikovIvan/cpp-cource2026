#pragma once
#include "animal.h"
#include <string>
#include <iostream>

class Cat: public Animal{
    public:
    Cat() : Animal(7, "грррр___мяу", "мошка", "kiti kat", "my house"){}
    static void song(){
        std::cout << "may" << std::endl;
    }
};

class Dog: public Animal{
    public:
    static void song(){
        std::cout << "gaw" << std::endl;
    Dog() : Animal(){}
};

class Fox : public Animal{
    public:
    static void song(){
        std::cout << "grrr" << std::endl;
    Fox() : Animal(){
        age = 1;
        sound = "грррр hhhhh";
        name = "ruzuk";
        eat = "мясо птицы";
        territoria = "курятник";  
    }
};



