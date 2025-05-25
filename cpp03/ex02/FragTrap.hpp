#pragma once

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
public:
  FragTrap(const std::string &name);
  FragTrap(const FragTrap &other);
  FragTrap &operator=(const FragTrap &rhs);
  ~FragTrap();

  // override attack
  void attack(const std::string &target);

  // special ability
  void highFivesGuys(void);
};
