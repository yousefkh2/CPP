#pragma once
#include "Weapon.hpp"
#include <string>

class HumanA
{
public:
    HumanA(const std::string &name, Weapon &weapon);
    ~HumanA();
	void attack() const;
private:
	std::string name;
	Weapon &weapon;
};
