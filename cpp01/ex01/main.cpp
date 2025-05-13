// #include "Zombie.hpp"

// int main() 
// {
// 	int hordeSize = 5;
// 	std::string zombieName = "White Walker";

// 	Zombie* horde = zombieHorde(hordeSize, zombieName);

// 	for (int i = 0; i < hordeSize; i++) 
// 	{
// 		horde[i].announce();
// 	}
// 	delete[] horde;

// 	return 0;
// }


#include <iostream>
#include "Zombie.hpp"

int main() {
    std::cout << "=== Positive N (5) ===\n";
    Zombie* h1 = zombieHorde(5, "Alice");
    if (!h1) std::cerr << "ERROR: Expected non-null for N=5\n";
    for (int i = 0; i < 5; ++i)
        h1[i].announce();      
    delete[] h1;        

    std::cout << "\n=== Zero N (0) ===\n";
    Zombie* h2 = zombieHorde(0, "Bob");
    if (h2)
        std::cerr << "ERROR: Expected nullptr for N=0\n";

    std::cout << "\n=== Negative N (-3) ===\n";
    Zombie* h3 = zombieHorde(-3, "Charlie");
    if (h3)
        std::cerr << "ERROR: Expected nullptr for N=-3\n";

    std::cout << "\n=== Single Zombie (1) ===\n";
    Zombie* h4 = zombieHorde(1, "Solo");
    h4[0].announce();               // prints “Solo: Braiiii…”
    delete[] h4;                    // one destructor

    return 0;
}
