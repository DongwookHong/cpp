#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed b( a );
	Fixed c;
	Fixed *p = &c;
	c = *p;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;


	return 0;
}


