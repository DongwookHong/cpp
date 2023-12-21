#include "Dog.hpp"

Dog::Dog() : Animal("Dog") {
  std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog() { std::cout << "Dog desctructor called" << std::endl; }

Dog::Dog(const Dog& ref) {
  std::cout << "Dog Copy constructor called" << std::endl;
  *this = ref;
}

Dog& Dog::operator=(const Dog& ref) {
  std::cout << "Dog Copy assignment constructor called" << std::endl;
  if (this != &ref) {
    Animal::operator=(ref);
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << this->type << "wal wal" << std::endl;
}
