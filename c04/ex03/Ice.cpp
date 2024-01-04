#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
  std::cout << "Ice default constructor called" << std::endl;
}
Ice::~Ice() { std::cout << "Ice destructor constructor called" << std::endl; }

Ice::Ice(const Ice& ref) : AMateria("ice") {
  std::cout << "Ice copy constructor called" << std::endl;
  *this = ref;
}

Ice& Ice::operator=(const Ice& ref) {
  if (this != &ref) {
    std::cout << "Cure Copy assignment constructor called" << std::endl;
    this->type = ref.getType();
  }
  return *this;
}

AMateria* Ice::clone() const { return new Ice(); }

void Ice::use(ICharacter& target) {
  std::cout << this->type << ": \" * shoots an ice bolt at " << target.getName()
            << " *\"" << std::endl;
}