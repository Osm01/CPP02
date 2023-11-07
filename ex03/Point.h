
#ifndef CPP02_POINT_H
#define CPP02_POINT_H

#include "Fixed.h"

class Point {
private:
	Fixed x;
	Fixed y;
public:
	Point();
	Point(const float x, const float y);
	Point(const Point &point);
	Point	&operator=(Point &other);
	Fixed	get_x( void ) const;
	Fixed	get_y( void ) const;
	bool	bsp( Point const a, Point const b, Point const c, Point const point);
	Point	vector(const Point &a, const Point &b);
	Fixed	magnitude_cross_product(const Point &ab, const Point &ac);
	Fixed	point_abs(Fixed magnitude);
	~Point();
};

#endif //CPP02_POINT_H
