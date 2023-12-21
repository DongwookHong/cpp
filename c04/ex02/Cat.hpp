#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        ~Cat();
        Cat(const Cat& ref);
        
        Cat& operator=(const Cat& ref);
        void makeSound() const;

        Brain *getBrain() const;
};