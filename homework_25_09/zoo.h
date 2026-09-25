#pragma once
#include <string>

class Animal {
protected:
    std::string name;
    int age;

public:
    Animal();
    Animal(const std::string& name, int age);
    Animal(const Animal& other);
    Animal(Animal&& other) noexcept;
    Animal& operator=(const Animal& other);
    Animal& operator=(Animal&& other) noexcept;
    virtual ~Animal();

    virtual void MakeSound() const;
    virtual void AskForFood() const;
    virtual void Move() const;
};

class Dog : public Animal {
public:
    Dog();
    Dog(const std::string& name, int age);
    Dog(const Dog& other);
    Dog(Dog&& other) noexcept;
    Dog& operator=(const Dog& other);
    Dog& operator=(Dog&& other) noexcept;
    ~Dog() override;

    void MakeSound() const override;
    void AskForFood() const override;
    void Move() const override;
};

class Fox : public Animal {
public:
    Fox();
    Fox(const std::string& name, int age);
    Fox(const Fox& other);
    Fox(Fox&& other) noexcept;
    Fox& operator=(const Fox& other);
    Fox& operator=(Fox&& other) noexcept;
    ~Fox() override;

    void MakeSound() const override;
    void AskForFood() const override;
    void Move() const override;
};

class Horse : public Animal {
public:
    Horse();
    Horse(const std::string& name, int age);
    Horse(const Horse& other);
    Horse(Horse&& other) noexcept;
    Horse& operator=(const Horse& other);
    Horse& operator=(Horse&& other) noexcept;
    ~Horse() override;

    void MakeSound() const override;
    void AskForFood() const override;
    void Move() const override;
};

class Dinosaur : public Animal {
public:
    Dinosaur();
    Dinosaur(const std::string& name, int age);
    Dinosaur(const Dinosaur& other);
    Dinosaur(Dinosaur&& other) noexcept;
    Dinosaur& operator=(const Dinosaur& other);
    Dinosaur& operator=(Dinosaur&& other) noexcept;
    ~Dinosaur() override;

    void MakeSound() const override;
    void AskForFood() const override;
    void Move() const override;
};