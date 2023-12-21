#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
  std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string _name)
    : ClapTrap(_name + "_clap_name"), ScavTrap(_name), FragTrap(_name) {
  std::cout << "DiamondTrap Constructor called" << std::endl;
  this->name = _name;
  FragTrap::Hp = 100;
  ScavTrap::Ep = 50;
  FragTrap::Ad = 30;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap& ref)
    : ClapTrap(ref.name + "_clap_name"),
      ScavTrap(ref.name),
      FragTrap(ref.name) {
  std::cout << "DiamondTrap Copy constructor called" << std::endl;
  *this = ref;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap& ref) {
  std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
  if (this != &ref) {
    ScavTrap::operator=(ref);
    FragTrap::operator=(ref);
    this->name = ref.name;
  }
  return *this;
}

void DiamondTrap::attack(const std::string& target) {
  ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
  std::cout << ClapTrap::name << " is not me, I'm " << this->name << std::endl;
}