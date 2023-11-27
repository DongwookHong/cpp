#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->num =0;
}


Fixed::~Fixed()
{
	std::cout<<"Destructor called"<<std::endl;
}

Fixed::Fixed(const Fixed& ref)
{
	std::cout<<"Copy constructor called" <<std::endl;

	*this = ref;
}

Fixed& Fixed::operator=(const Fixed& ref)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	this->num = ref.getRawBits();
	return *this;
}


int Fixed::getRawBits( void ) const
{
	std::cout<<"getRawBits member function called" <<std::endl;
	return this->num;
}


void Fixed::setRawBits( int const raw )
{
	std::cout<<"setRawBits member function called" <<std::endl;
	this->num = raw;
}