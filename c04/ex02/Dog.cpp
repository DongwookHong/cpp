#include "Dog.hpp"

Dog::Dog():Animal("Dog"){
    std::cout<<"Dog default constructor called"<<std::endl;
    this->brain = new Brain();
}

Dog::~Dog(){
    delete this->brain;
    std::cout<<"Dog desctructor called"<<std::endl;
}

Dog::Dog(const Dog& ref)
{
    std::cout<<"Dog Copy constructor called"<<std::endl;
    *this = ref;
}

Dog& Dog::operator=(const Dog& ref)
{
    std::cout<<"Dog Copy assignment constructor called"<<std::endl;
    if(this!=&ref)
    {
        this->type = ref.type;
        delete this->brain;
        this->brain = new Brain(*ref.brain);
    }
    return *this;
}


void Dog::makeSound() const
{
    std::cout<<this->type << " wal wal"<<std::endl;     
}


Brain* Dog::getBrain() const
{
    return this->brain;
}