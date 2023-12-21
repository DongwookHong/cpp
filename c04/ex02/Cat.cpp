#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
    std::cout<<"Cat default constructor called"<<std::endl;
    this->brain =new Brain();
}

Cat::~Cat(){

    delete this->brain;
    std::cout<<"Cat desctructor called"<<std::endl;
}


Cat::Cat(const Cat& ref)
{
    std::cout<<"Cat Copy constructor called"<<std::endl;
    *this = ref;
}

Cat& Cat::operator=(const Cat& ref)
{
    std::cout<<"Cat Copy assignment constructor called"<<std::endl;
    if(this!=&ref)
    {
        this->type = ref.type;
        delete this->brain;
        this->brain = new Brain(*ref.brain);
    }
    return *this;
}


void Cat::makeSound() const
{
    std::cout<<"mew"<<std::endl;     
}


Brain *Cat::getBrain() const
{
    return this->brain;
}