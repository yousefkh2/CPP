#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "--- SIMPLE SOUND TESTS ---\n";
    Animal* animals[4];
    for (int i = 0; i < 4; ++i) {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i) {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i)
        delete animals[i];

    return 0;
}
