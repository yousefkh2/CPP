#pragma once
#include <iostream>
#include <string>


class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name); // TODO: did they ask for this parameterized constructor?
		~Zombie();
		void announce() const
		{
			std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

//TODO: we have to review whether we made it into orthodox canonical form or not