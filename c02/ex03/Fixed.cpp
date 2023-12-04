#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout<<"Default constructor called"<<std::endl;
	this->num =0;
}

Fixed::Fixed(const int numInt)
{
	std::cout<<"Int constructor called"<<std::endl;
	this->num = numInt<<bits;
}
		
Fixed::Fixed(const float numFloat)
{
	std::cout<<"Float constructor called"<<std::endl;
	this->num = roundf(numFloat * (1 << bits));;
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
	return ((float)this->num / (1 << bits));
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
	return os<<fix.toFloat();
}


bool Fixed::operator >(const Fixed& a) const{
	return this->num >a.num;
}
bool Fixed::operator <(const Fixed& a) const{
	return this->num <a.num;
}
bool Fixed::operator >=(const Fixed& a) const{
	return this->num >=a.num;
}
bool Fixed::operator <=(const Fixed& a) const{
	return this->num <=a.num;
}
bool Fixed::operator ==(const Fixed& a) const{
	return this->num ==a.num;
}
bool Fixed::operator !=(const Fixed& a) const{
	return this->num != a.num;
}


float Fixed::operator +(const Fixed& a){
	return toFloat() + a.toFloat();
}

float Fixed::operator -(const Fixed& a)
{
	return toFloat() - a.toFloat();
}

float Fixed::operator *(const Fixed& a)
{
	return toFloat() * a.toFloat();
}


float Fixed::operator /(const Fixed& a)
{
	if (a.num == 0)
	{
		std::cout<< " divid by 0 is not considered"<<std::endl;
		return 0;
	}
	return toFloat() / a.toFloat();
}

Fixed& Fixed::operator ++( void ){
	this->num++;
	return *this;
}

Fixed& Fixed::operator --( void ){
	this->num--;
	return *this;
}


Fixed Fixed::operator ++( int ){
	Fixed	result(*this);
	++(*this);
	return result;
}

Fixed Fixed::operator --( int ){
	Fixed	result(*this);
	--(*this);
	return result;
}

Fixed& Fixed::min(Fixed& a,Fixed& b)
{
	return (a.num < b.num ? a : b); 	
}


const Fixed& Fixed::min(const Fixed&  a,const Fixed& b){
	return (a.num < b.num ? a : b);
}





Fixed& Fixed::max(Fixed& a,Fixed& b)
{
	return (a.num>= b.num ? a : b); 
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b){
	return (a.num >= b.num ? a: b);
}
