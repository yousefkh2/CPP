#include "Dog.hpp"

Dog::Dog() : brain(new Brain()) {
	type = "Dog";
	std::cout << "[Dog] Constructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "[Dog] Copy constructor called\n";
	brain = new Brain(*other.brain);
	type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "[Dog] Copy assignment called\n";
    if (this != &other) {
        Animal::operator=(other);       
        *brain = *other.brain;
        type    = other.type;
    }
    return *this;
}

Dog::~Dog() {
	std::cout << "[Dog] Destructor called\n";
	delete brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!\n";
}

Brain* Dog::getBrain() const {
	return brain;
}