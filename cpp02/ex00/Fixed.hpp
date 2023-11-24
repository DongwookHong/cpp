#pragma once
#include <iostream>

class Fixed {
	private:
		/* data */
		int 				num;
		static const int	bits;
	public:
		Fixed();
		Fixed(const Fixed& ref);
		~Fixed();
		
		
		Fixed& operator=(const Fixed& ref);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
