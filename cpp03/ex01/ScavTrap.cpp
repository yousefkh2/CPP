#include "ScavTrap.hpp"

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ScavTrap [" << _name << "] constructed! "
            << "(HP=" << _hitPoints << ", EN=" << _energyPoints
            << ", ATK=" << _attackDamage << ")\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
  std::cout << "ScavTrap [" << _name << "] copy-constructed\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs) {
  ClapTrap::operator=(rhs);
  std::cout << "ScavTrap [" << _name << "] assigned\n";
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap [" << _name << "] destructed\n";
}

void ScavTrap::attack(const std::string &target) {
  if (_hitPoints == 0) {
    std::cout << "ScavTrap [" << _name
              << "] has no hit points left and cannot attack.\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << "ScavTrap [" << _name
              << "] has no energy left and cannot attack.\n";
    return;
  }
  --_energyPoints;
  std::cout << "ScavTrap [" << _name << "] fiercely attacks [" << target
            << "], causing " << _attackDamage
            << " points of damage! (EN=" << _energyPoints << ")\n";
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap [" << _name << "] has entered Gate keeper mode.\n";
}
