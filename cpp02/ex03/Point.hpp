#pragma once
#include <iostream>

class Point
{
	private:
		const float	x;
		const float	y;
	public:
		Point();
		~Point();
		Point(const float _x, const float _y);
		Point(const Point& ref);
		
		Point& operator=(const Point& ref);
};



 bool bsp( Point const a, Point const b, Point const c, Point const point);


Point::Point(const Point& ref)
{
	std::cout<<"Copy constructor called" <<std::endl;
	*this = ref;
}
