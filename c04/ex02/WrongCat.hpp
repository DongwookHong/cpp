#pragma once
#include <iostream>
#include <string>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    public:
        WrongCat();
        ~WrongCat();
        WrongCat(const WrongCat& ref);
        
        WrongCat& operator=(const WrongCat& ref);
        void makeSound() const;
};