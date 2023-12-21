#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {

	const Dog *dog = new Dog();
	const Cat *cat = new Cat();

	std::cout << dog->getType() << "\n";
	dog->makeSound();
	std::cout << cat->getType() << "\n";
	cat->makeSound();
	std::cout << std::endl;
	
	delete(dog);
	delete(cat);

	return 0;
}