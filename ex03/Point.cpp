
#include "Point.h"

Point::Point() : x() , y()
{}

Point::Point(const float px, const float py) : x(px) , y(py)
{}

Point::Point(const Point &point) : x(point.x) , y(point.y)
{}

Point	&Point::operator=(Point &other){
	if (this != &other)
	{
		this->x = other.x;
		this->y = other.y;
	}
	return (*this);
}

Fixed	Point::get_x(void) const
{
	return (this->x);
}

Fixed	Point::get_y(void) const
{
	return (this->y);
}

Fixed Point::point_abs(Fixed magnitude)
{
	if (magnitude < 0)
		magnitude = magnitude * -1;
	return (magnitude);
}

Point Point::vector(const Point &a, const Point &b)
{
	Point ab;
	ab.x = Fixed(b.x - a.x);
	ab.y = Fixed(b.y - a.y);
	return (ab);
}

Fixed Point::magnitude_cross_product(const Point &ab, const Point &ac)
{
	return ((ab.x * ac.y) - (ac.x * ab.y));
}

bool Point::bsp(const Point a, const Point b, const Point c, const Point point)
{
	Point	AB = vector(a, b);
	Point	BC = vector(b, c);
	Point	AC = vector(a, c);
	Point	XA = vector(point, a);
	Point	XB = vector(point, b);
	Point	XC = vector(point, c);

	Fixed Area_of_triangle = point_abs(magnitude_cross_product(AB, AC) / 2);
	Fixed total_area = (point_abs(magnitude_cross_product(AB, XA)) + point_abs(magnitude_cross_product(BC, XB))\
	+ point_abs(magnitude_cross_product(AC, XC))) / 2;
	if (total_area == Area_of_triangle)
		return (true);
	return (false);
}

Point::~Point()
{}