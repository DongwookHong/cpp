#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main()
{
    Animal *a = new Animal();
    Animal *b = new Cat();
    Animal *c = new Dog();
    

    Cat *d = new Cat();
    Dog *e = new Dog();

    a->makeSound();
    b->makeSound();
    std::cout << b->getType() << " " <<std::endl; 

    c->makeSound();
    std::cout << c->getType() << " " <<std::endl; 


    d->makeSound();
    std::cout << d->getType() << " " <<std::endl; 

    e->makeSound();
    std::cout << e->getType() << " " <<std::endl; 
    
    
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;


    


    std::cout << "------------------test2----------------" <<std::endl;

    WrongAnimal *ca = new WrongAnimal();
    WrongAnimal *w = new WrongCat();

    ca->makeSound();
    std::cout << ca->getType() << " " <<std::endl; 
    w->makeSound();
    std::cout << w->getType() << " " <<std::endl; 

    delete w;
    delete ca;
}