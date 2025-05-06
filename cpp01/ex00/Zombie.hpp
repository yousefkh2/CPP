#pragma once
#include <string>


class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name); // TODO: did they ask for this parameterized constructor? and if there's a reason, then why have the orignal default constructor? 
		~Zombie();
		void announce() const;
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

//TODO: we have to review whether we made it into orthodox canonical form or not