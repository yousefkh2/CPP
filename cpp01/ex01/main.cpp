#include "Zombie.hpp"

int main() {
	int hordeSize = 5;
	std::string zombieName = "Walker";

	Zombie* horde = zombieHorde(hordeSize, zombieName);

	for (int i = 0; i < hordeSize; i++) {
		horde[i].announce();
	}
	delete[] horde;

	return 0;
}