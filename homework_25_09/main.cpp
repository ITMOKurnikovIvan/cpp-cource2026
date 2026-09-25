#include "zoo.h"
#include <iostream>

int main() {
    Dog dog("собачка", 4);
    Fox fox("хитрая", 3);
    Horse horse("лошадка", 7);
    Dinosaur dino("терранозавр", 100);

    std::cout << "собака\n";
    dog.MakeSound();
    dog.AskForFood();
    dog.Move();

    std::cout << "\nлиса\n";
    fox.MakeSound();
    fox.AskForFood();
    fox.Move();

    std::cout << "\nлошадь\n";
    horse.MakeSound();
    horse.AskForFood();
    horse.Move();

    std::cout << "\nдинозавр\n";
    dino.MakeSound();
    dino.AskForFood();
    dino.Move();

    return 0;
}