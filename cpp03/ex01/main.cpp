#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
  std::cout << "\n=== ClapTrap Basic Tests ===\n";
  ClapTrap ct("CT-Base");
  ct.attack("Bandit");
  ct.takeDamage(4);
  ct.beRepaired(2);

  std::cout << "\n=== ScavTrap Construction & Assignment ===\n";
  ScavTrap s1("SC1");
  ScavTrap s2(s1);
  ScavTrap s3("SC3");
  s3 = s1;

  std::cout << "\n=== ScavTrap attack() override ===\n";
  s1.attack("Raider");

  std::cout << "\n=== ScavTrap guardGate() ===\n";
  s1.guardGate();

  std::cout << "\n=== ScavTrap takeDamage & beRepaired ===\n";
  s1.takeDamage(60);
  s1.beRepaired(30);

  std::cout << "\n=== ScavTrap energy exhaustion ===\n";
  for (int i = 0; i < 51; ++i)
    s1.attack("Dummy");
  s1.beRepaired(5);

  std::cout << "\nEnd of tests. Destructors will now run:\n";
  return 0;
}
