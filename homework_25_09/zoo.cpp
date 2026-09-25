#include "zoo.h"
#include <iostream>

//животное 
Animal::Animal() : name("Unknown"), age(0) {}

Animal::Animal(const std::string& name, int age)
    : name(name), age(age) {}

Animal::Animal(const Animal& other)
    : name(other.name), age(other.age) {}

Animal::Animal(Animal&& other) noexcept
    : name(std::move(other.name)), age(other.age) {
    other.age = 0;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        name = other.name;
        age = other.age;
    }
    return *this;
}

Animal& Animal::operator=(Animal&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        age = other.age;
        other.age = 0;
    }
    return *this;
}

Animal::~Animal() {}

void Animal::MakeSound() const {
    std::cout << name << ": какой-то звук\n";
}
void Animal::AskForFood() const {
    std::cout << name << ": хочу еды\n";
}
void Animal::Move() const {
    std::cout << name << ": двигается\n";
}

// собака
Dog::Dog() : Animal("Dog", 3) {}
Dog::Dog(const std::string& n, int a) : Animal(n, a) {}
Dog::Dog(const Dog& other) : Animal(other) {}
Dog::Dog(Dog&& other) noexcept : Animal(std::move(other)) {}
Dog& Dog::operator=(const Dog& other) {
    Animal::operator=(other);
    return *this;
}
Dog& Dog::operator=(Dog&& other) noexcept {
    Animal::operator=(std::move(other));
    return *this;
}
Dog::~Dog() {}

void Dog::MakeSound() const {
    std::cout << name << ": Гав-гав!\n";
}
void Dog::AskForFood() const {
    std::cout << name << ": хочу мясо и косточку\n";
}
void Dog::Move() const {
    std::cout << name << ": бежит\n";
}

// лиса
Fox::Fox() : Animal("Fox", 2) {}
Fox::Fox(const std::string& n, int a) : Animal(n, a) {}
Fox::Fox(const Fox& other) : Animal(other) {}
Fox::Fox(Fox&& other) noexcept : Animal(std::move(other)) {}
Fox& Fox::operator=(const Fox& other) {
    Animal::operator=(other);
    return *this;
}
Fox& Fox::operator=(Fox&& other) noexcept {
    Animal::operator=(std::move(other));
    return *this;
}
Fox::~Fox() {}

void Fox::MakeSound() const {
    std::cout << name << ": Тяв-тяв!\n";
}
void Fox::AskForFood() const {
    std::cout << name << ": хочу курочку\n";
}
void Fox::Move() const {
    std::cout << name << ": крадётся\n";
}

// лошадка
Horse::Horse() : Animal("Horse", 5) {}
Horse::Horse(const std::string& n, int a) : Animal(n, a) {}
Horse::Horse(const Horse& other) : Animal(other) {}
Horse::Horse(Horse&& other) noexcept : Animal(std::move(other)) {}
Horse& Horse::operator=(const Horse& other) {
    Animal::operator=(other);
    return *this;
}
Horse& Horse::operator=(Horse&& other) noexcept {
    Animal::operator=(std::move(other));
    return *this;
}
Horse::~Horse() {}

void Horse::MakeSound() const {
    std::cout << name << ": Игого!\n";
}
void Horse::AskForFood() const {
    std::cout << name << ": хочу овёс\n";
}
void Horse::Move() const {
    std::cout << name << ": скачет\n";
}

// динозавр
Dinosaur::Dinosaur() : Animal("Dinosaur", 100) {}
Dinosaur::Dinosaur(const std::string& n, int a) : Animal(n, a) {}
Dinosaur::Dinosaur(const Dinosaur& other) : Animal(other) {}
Dinosaur::Dinosaur(Dinosaur&& other) noexcept : Animal(std::move(other)) {}
Dinosaur& Dinosaur::operator=(const Dinosaur& other) {
    Animal::operator=(other);
    return *this;
}
Dinosaur& Dinosaur::operator=(Dinosaur&& other) noexcept {
    Animal::operator=(std::move(other));
    return *this;
}
Dinosaur::~Dinosaur() {}

void Dinosaur::MakeSound() const {
    std::cout << name << ": РРРРРРРР\n";
}
void Dinosaur::AskForFood() const {
    std::cout << name << ": хочу мяса побольше\n";
}
void Dinosaur::Move() const {
    std::cout << name << ": топает\n";
}