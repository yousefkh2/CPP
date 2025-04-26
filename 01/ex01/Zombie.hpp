#pragma once
#include <iostream>
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
		void setName(const std::string &name); // why did we add setter here and not in the first exercise?
		//if no reason, then we can remove it

};

Zombie* zombieHorde(int N, std::string name);