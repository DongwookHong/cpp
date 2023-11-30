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
	if (this != &ref)
		num = ref.getRawBits();
	return *this;

}


int Fixed::getRawBits( void ) const
{
	return this->num;
}


void Fixed::setRawBits( int const raw )
{
	this->num = raw;
}