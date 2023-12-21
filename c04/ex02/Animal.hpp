#pragma once
#include <iostream>
#include <string>


class Animal
{
    protected:
        std::string     type;
    public:
        Animal();
        virtual ~Animal();
        Animal(std::string _name);
        Animal(const Animal& ref);
        
        Animal& operator=(const Animal& ref);

        virtual void makeSound() const = 0;
        std::string getType() const;
};