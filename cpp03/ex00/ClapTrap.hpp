#pragma once

#include <iostream>
#include <string>

class ClapTrap {
private:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

public:
  // Orthodox Canonical Form
  ClapTrap(const std::string &name);
  ClapTrap(const ClapTrap &other);
  ClapTrap &operator=(const ClapTrap &rhs);
  ~ClapTrap();

  // actions
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
};
