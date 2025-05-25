// main.cpp
#include "ClapTrap.hpp"
#include <iostream>

int main() {
  std::cout << "\n--- Construction & Destruction ---\n";
  ClapTrap alpha("Alpha");
  ClapTrap beta(alpha);
  ClapTrap gamma("Gamma");
  gamma = alpha;

  std::cout << "\n--- Attack (costs 1 energy) ---\n";
  alpha.attack("Target1");
  alpha.attack("Target2");

  std::cout << "\n--- Take Damage ---\n";
  alpha.takeDamage(5);
  alpha.takeDamage(10); // should destroy

  std::cout << "\n--- Repair (costs 1 energy) ---\n";
  beta.beRepaired(4);
  // drain beta's energy
  for (int i = 0; i < 11; ++i)
    beta.beRepaired(1);

  std::cout << "\n--- Dead cannot act ---\n";
  alpha.attack("Anything");
  alpha.beRepaired(1);
  alpha.takeDamage(1);

  std::cout << "\nEnd of tests, destructors will now run:\n";
  return 0;
}
