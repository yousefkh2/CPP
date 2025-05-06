#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(const std::string& name) : name(name), weapon(nullptr) {}

void HumanB::setWeapon(Weapon& w) {
    weapon = &w;
}

void HumanB::attack() const {
	if (weapon) 
	{
		std::cout << name 
				  << " attacks with their " 
				  << weapon->getType() 
				  << '\n';
	} 
	else
	{
		std::cout << name
				  << " has no weapon!\n";
	}
}
