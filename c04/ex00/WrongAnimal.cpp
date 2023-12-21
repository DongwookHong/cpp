#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("WrongAnimal"){
    std::cout<<"WrongAnimal default constructor called"<<std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout<<"WrongAnimal desctructor called"<<std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref)
{
    std::cout<<"WrongAnimal Copy constructor called"<<std::endl;
    *this = ref;
}


WrongAnimal::WrongAnimal(std::string pet): type(pet)
{
    std::cout<<"WrongAnimal constructor called"<<std::endl;
}



WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
    std::cout<<"WrongAnimal Copy assignment constructor called"<<std::endl;
    if(this!=&ref)
    {
        this->type = ref.type;
    }
    return *this;
}


void WrongAnimal::makeSound() const
{
    std::cout<<"Silence"<<std::endl;     
}

std::string WrongAnimal::getType() const
{
    return this->type;
}