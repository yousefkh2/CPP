#pragma once
#include <string>


class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie();
		void announce() const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);