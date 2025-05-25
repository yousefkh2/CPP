#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "FragTrap [" << _name << "] constructed! "
            << "(HP=" << _hitPoints << ", EN=" << _energyPoints
            << ", ATK=" << _attackDamage << ")\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  std::cout << "FragTrap [" << _name << "] copy-constructed\n";
}

FragTrap &FragTrap::operator=(const FragTrap &rhs) {
  ClapTrap::operator=(rhs);
  std::cout << "FragTrap [" << _name << "] assigned\n";
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap [" << _name << "] destructed\n";
}

void FragTrap::attack(const std::string &target) {
  if (_hitPoints == 0) {
    std::cout << "FragTrap [" << _name
              << "] has no hit points left and cannot attack.\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << "FragTrap [" << _name
              << "] has no energy left and cannot attack.\n";
    return;
  }
  --_energyPoints;
  std::cout << "FragTrap [" << _name << "] blasts [" << target << "], causing "
            << _attackDamage << " points of damage! (EN=" << _energyPoints
            << ")\n";
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap [" << _name << "] requests: \"High five, guys?!\"\n";
}
