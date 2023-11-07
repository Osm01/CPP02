
# include "Point.h"

int main( void ) {
	Point a(0,0);
	Point b(0,3);
	Point c(4, 0);
	const Point x(4.000001f,0);

	if (a.bsp(a, b, c, x))
		std::cout << GREEN << "inside" << RESET << std::endl;
	else
		std::cout << RED <<"outside" << RESET << std::endl;
	return 0;
}
