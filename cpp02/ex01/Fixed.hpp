#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	private:
		/* data */
		int 				num;
		static const int	bits = 8 ;
	public:
		Fixed(const Fixed& ref);
		Fixed(const int numInt);
		Fixed(const float numFloat);

		Fixed();
		~Fixed();
		
		
		Fixed&	operator=(const Fixed& ref);

		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream& os ,const Fixed& fix);
