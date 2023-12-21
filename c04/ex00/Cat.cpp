#include "Cat.hpp"

Cat::Cat() : Animal("Cat") {
  std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat() { std::cout << "Cat desctructor called" << std::endl; }

Cat::Cat(const Cat& ref) {
  std::cout << "Cat Copy constructor called" << std::endl;
  *this = ref;
}

Cat& Cat::operator=(const Cat& ref) {
  std::cout << "Cat Copy assignment constructor called" << std::endl;
  if (this != &ref) {
    Animal::operator=(ref);
  }
  return *this;
}

void Cat::makeSound() const { std::cout << "mew" << std::endl; }
