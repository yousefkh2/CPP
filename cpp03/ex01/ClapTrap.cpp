#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
  std::cout << "ClapTrap [" << _name << "] constructed! "
            << "(HP=" << _hitPoints << ", EN=" << _energyPoints
            << ", ATK=" << _attackDamage << ")\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
    : _name(other._name), _hitPoints(other._hitPoints),
      _energyPoints(other._energyPoints), _attackDamage(other._attackDamage) {
  std::cout << "ClapTrap [" << _name << "] copy-constructed\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs) {
  if (this != &rhs) {
    _name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;
  }
  std::cout << "ClapTrap [" << _name << "] assigned\n";
  return *this;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap [" << _name << "] destructed\n";
}

void ClapTrap::attack(const std::string &target) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap [" << _name
              << "] has no hit points left and cannot attack.\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << "ClapTrap [" << _name
              << "] has no energy left and cannot attack.\n";
    return;
  }
  --_energyPoints;
  std::cout << "ClapTrap [" << _name << "] attacks [" << target << "], causing "
            << _attackDamage << " points of damage! "
            << "(EN=" << _energyPoints << ")\n";
}

void ClapTrap::takeDamage(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap [" << _name << "] is already destroyed.\n";
    return;
  }
  if (amount >= _hitPoints) {
    _hitPoints = 0;
    std::cout << "ClapTrap [" << _name << "] takes " << amount
              << " damage and is now destroyed!\n";
  } else {
    _hitPoints -= amount;
    std::cout << "ClapTrap [" << _name << "] takes " << amount
              << " damage, remaining HP=" << _hitPoints << "\n";
  }
}

void ClapTrap::beRepaired(unsigned int amount) {
  if (_hitPoints == 0) {
    std::cout << "ClapTrap [" << _name
              << "] is destroyed and cannot be repaired.\n";
    return;
  }
  if (_energyPoints == 0) {
    std::cout << "ClapTrap [" << _name
              << "] has no energy left and cannot repair.\n";
    return;
  }
  --_energyPoints;
  _hitPoints += amount;
  std::cout << "ClapTrap [" << _name << "] is repaired by " << amount
            << " points, HP=" << _hitPoints << " (EN=" << _energyPoints
            << ")\n";
}
