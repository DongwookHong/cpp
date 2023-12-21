#include "Animal.hpp"


Animal::Animal():type("Animal"){
    std::cout<<"Animal default constructor called"<<std::endl;
}

Animal::~Animal(){
    std::cout<<"Animal desctructor called"<<std::endl;
}

Animal::Animal(std::string pet): type(pet)
{
    std::cout<<"Animal constructor called"<<std::endl;
}


Animal::Animal(const Animal& ref)
{
    std::cout<<"Animal Copy constructor called"<<std::endl;
    *this = ref;
}

Animal& Animal::operator=(const Animal& ref)
{
    std::cout<<"Animal Copy assignment constructor called"<<std::endl;
    if(this!=&ref)
    {
        this->type = ref.type;
    }
    return *this;
}


void Animal::makeSound() const
{
    std::cout<<"Silence"<<std::endl;     
}

std::string Animal::getType() const
{
	return this->type;
}