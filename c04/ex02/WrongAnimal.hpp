#pragma once
#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string     type;
    public:
        WrongAnimal();
        virtual ~WrongAnimal();
        WrongAnimal(std::string _name);
        WrongAnimal(const WrongAnimal& ref);
        
        WrongAnimal& operator=(const WrongAnimal& ref);

        virtual void makeSound() const;
        std::string getType() const;
};