#pragma once
#include <iostream>

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

		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt(void) const;
		
	
		Fixed&	operator=(const Fixed& ref);
		
		bool operator >(const Fixed& a) const;
		bool operator <(const Fixed& a) const;
		bool operator >=(const Fixed& a) const;
		bool operator <=(const Fixed& a) const;
		bool operator ==(const Fixed& a) const;
		bool operator !=(const Fixed& a) const;

		float operator +(const Fixed& a);
		float operator -(const Fixed& a);
		float operator *(const Fixed& a);
		float operator /(const Fixed& a);
		
		Fixed& operator ++( void );
		Fixed& operator --( void );

		Fixed operator ++( int );
		Fixed operator --( int );

		static Fixed& min(Fixed& a,Fixed& b);
		static const Fixed& min(const Fixed&  a,const Fixed& b);

		static Fixed& max(Fixed& a,Fixed& b);
		static const Fixed& max(const Fixed&  a,const Fixed& b);

};


std::ostream& operator<<(std::ostream& os ,const Fixed& fix);