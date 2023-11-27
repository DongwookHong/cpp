#pragma once
#include <iostream>

class Fixed {
	private:
		/* data */
		int 				num;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed& ref);
		~Fixed();
		
		float	toFloat( void ) const;
		int		toInt( void ) const;	
		Fixed& operator=(const Fixed& ref);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
};
