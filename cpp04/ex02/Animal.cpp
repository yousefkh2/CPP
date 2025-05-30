#include "Animal.hpp"

Animal::Animal() : type("Animal") {
    std::cout << "[Animal] Constructor called\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
    std::cout << "[Animal] Copy constructor called\n";
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "[Animal] Copy assignment operator called\n";
    if (this != &other)
        type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "[Animal] Destructor called\n";
}

std::string Animal::getType() const {
    return type;
}
