
#include "Fixed.h"

Fixed::Fixed()
{
	this->fixed_point_number = 0;
}

Fixed::Fixed(const int int_fixed)
{
	this->fixed_point_number = int_fixed * (1 << this->number_fractional_bits);
}

Fixed::Fixed(const float float_fixed_point)
{
	this->fixed_point_number = roundf(float_fixed_point * (1 << this->number_fractional_bits));
}

Fixed::Fixed(const Fixed &fixed)
{
	this->fixed_point_number = fixed.fixed_point_number;
}

int Fixed::getRawBits() const
{
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

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
	{
		this->fixed_point_number = other.fixed_point_number;
	}
	return (*this);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->fixed_point_number == other.fixed_point_number);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->fixed_point_number != other.fixed_point_number);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->fixed_point_number < other.fixed_point_number);
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->fixed_point_number > other.fixed_point_number);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->fixed_point_number <= other.fixed_point_number);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->fixed_point_number >= other.fixed_point_number);
}

Fixed	Fixed::operator+(const Fixed &other) const
{
	Fixed	fixed;
	fixed.fixed_point_number = this->fixed_point_number + other.fixed_point_number;
	return (fixed);
}

Fixed	Fixed::operator-(const Fixed &other) const
{
	Fixed	fixed;
	fixed.fixed_point_number = this->fixed_point_number - other.fixed_point_number;
	return (fixed);
}

Fixed	Fixed::operator*(const Fixed &other) const
{
	Fixed	fixed;
	fixed.fixed_point_number = (this->fixed_point_number * other.fixed_point_number) >> (this->number_fractional_bits);
	return (fixed);
}

Fixed	Fixed::operator/(const Fixed &other) const
{
	Fixed	fixed;
	fixed.fixed_point_number = (this->fixed_point_number * (1 << this->number_fractional_bits)) / (other.fixed_point_number);
	return (fixed);
}

Fixed	&Fixed::operator++()
{
	this->fixed_point_number ++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	++(*this);
	return (tmp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}