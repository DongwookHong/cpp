#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
  std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name) {
  std::cout << "ScavTrap Constructor called" << std::endl;
  this->Hp = 100;
  this->Ep = 50;
  this->Ad = 20;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& ref) : ClapTrap(ref.name) {
  std::cout << "ScavTrap Copy constructor called" << std::endl;
  *this = ref;
}

ScavTrap& ScavTrap::operator=(ScavTrap& ref) {
  std::cout << "ScavTrap Copy assignment operator called" << std::endl;
  if (this != &ref) {
    ClapTrap::operator=(ref);
  }
  return *this;
}

void ScavTrap::guardGate(void) {
  std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
};

void ScavTrap::attack(const std::string& target) {
  if (this->name.empty()) return;
  if (this->Hp == 0)
    std::cout << "I'm already Dead" << std::endl;
  else if (this->Ep == 0)
    std::cout << "I need Ep" << std::endl;
  else {
    std::cout << "ScavTrap " << this->name << " attacks " << target
              << ", causing " << this->Ad << " points of damage!" << std::endl;
    Ep--;
  }
}