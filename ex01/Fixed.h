
#ifndef CPP02_FIXED_H
# define CPP02_FIXED_H

# include <iostream>
# include <cmath>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

class Fixed {
private:
	int                 fixed_point_number;
	static const int    number_fractional_bits = 8;
public:
	Fixed();
	Fixed(const int int_fixed_point);
	Fixed(const float float_fixed_point);
	Fixed(const Fixed &fixed);
	Fixed   &operator=(const Fixed &fixed);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	~Fixed();
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif //CPP02_FIXED_H
