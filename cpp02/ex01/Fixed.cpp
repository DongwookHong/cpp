#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->num =0;
}

Fixed::Fixed(const int numInt)
{
	std::cout<<"Int constructor called"<<std::endl;
	printf("this value is %d\n",numInt);
	this->num = numInt<<bits;
	printf("this value is %d\n",this->num);
}
		
Fixed::Fixed(const float numFloat)
{
	std::cout<<"Float constructor called"<<std::endl;
	printf("this value is %f\n",numFloat);
	this->num = roundf(numFloat * 256 );
	printf("%d\n",this->num);
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


float	Fixed::toFloat( void ) const{
	return ((float)this->num / 256 );
}


int		Fixed::toInt(void) const{
	return (this->num >> bits);
}


int Fixed::getRawBits( void ) const
{
	return this->num;
}


void Fixed::setRawBits( int const raw )
{
	this->num = raw;
}

std::ostream& operator<<(std::ostream& os ,const Fixed& fix)
{
	return os << fix.toFloat();
}
