#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : name("Default") {
}

Zombie::Zombie(std::string name) : name(name) {
}

Zombie::~Zombie() {
	std::cout << name << " is dead." << std::endl;
}

void Zombie::announce() const {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
