
#include "Fixed.h"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_number = 0;
}

Fixed::Fixed(const int int_fixed)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_number = int_fixed * (1 << this->number_fractional_bits);
}

Fixed::Fixed(const float float_fixed_point)
{
	// 1 << 8 = 100000000 = 256 {example 42.42 = 101010.0110101110000101001 take just 8 bit after '.' and save it will be [10101001101011].xxxxxx }
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_number = roundf(float_fixed_point * (1 << this->number_fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_number = fixed.fixed_point_number;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
		this->fixed_point_number = fixed.fixed_point_number;
	return (*this);
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_point_number);
}

void Fixed::setRawBits(const int raw)
{
	this->fixed_point_number = raw;
}

float Fixed::toFloat() const
{
	// divided by 1 << 8 = 256 to go back to init float value
	return ((float) this->fixed_point_number / (1 << this->number_fractional_bits));
}

int Fixed::toInt() const
{
	return (this->fixed_point_number / (1 << this->number_fractional_bits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}
