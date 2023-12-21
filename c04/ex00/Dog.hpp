#pragma once


#include "Animal.hpp"

class Dog: public Animal
{
    private:
        
    public:
        Dog();
        ~Dog();
        Dog(const Dog& ref);
        
        Dog& operator=(const Dog& ref);

        void makeSound() const;
};