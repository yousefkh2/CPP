#pragma once
#include "Weapon.hpp"
#include <string>

class HumanB
{
public:
    HumanB(const std::string &name, Weapon &weapon);
    ~HumanB();
	void attack() const;
private:
	std::string name;
	Weapon &weapon;
};
