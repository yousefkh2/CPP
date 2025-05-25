#include "FragTrap.hpp"
#include <iostream>

int main() {
  std::cout << "\n=== FragTrap Construction & Assignment ===\n";
  FragTrap ft1("FT-1");
  FragTrap ft2(ft1);
  FragTrap ft3("Dummy");
  ft3 = ft1;

  std::cout << "\n=== FragTrap attack() override ===\n";
  ft1.attack("Target-A");

  std::cout << "\n=== FragTrap highFivesGuys() ===\n";
  ft1.highFivesGuys();

  std::cout << "\n=== FragTrap takeDamage() & beRepaired() ===\n";
  ft1.takeDamage(50);
  ft1.beRepaired(20);

  std::cout << "\n=== FragTrap energy exhaustion & dead ops ===\n";
  for (int i = 0; i < 101; ++i)
    ft1.attack("Dummy");
  ft1.beRepaired(5);

  std::cout << "\n=== End of tests: destructors will now run ===\n";
  return 0;
}
