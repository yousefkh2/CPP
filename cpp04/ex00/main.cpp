#include <iostream>

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound(); 
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    std::cout << "\n----- WRONG ANIMAL TESTS -----\n";
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    wrong->makeSound(); 
    wrongCat->makeSound(); 

    delete wrong;
    delete wrongCat;

    return 0;
}
