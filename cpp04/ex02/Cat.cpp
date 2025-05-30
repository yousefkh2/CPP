#include "Cat.hpp"

Cat::Cat() : brain(new Brain()) {
    type = "Cat";
    std::cout << "[Cat] Constructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "[Cat] Copy constructor called\n";
	brain = new Brain(*other.brain);
	type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "[Cat] Copy assignment operator called\n";
    if (this != &other) {
        Animal::operator=(other);
		*brain = *other.brain;
		type = other.type;
	}
    return *this;
}

Cat::~Cat() {
    std::cout << "[Cat] Destructor called\n";
	delete brain;
}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}

Brain* Cat::getBrain() const {
	return brain;
}