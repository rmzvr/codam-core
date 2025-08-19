#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed::Fixed(int const int_number)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixedPointValue = int_number << Fixed::_fractionalBits;
}

Fixed::Fixed(float const float_number)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixedPointValue = roundf(float_number * (1 << Fixed::_fractionalBits));
}

int	Fixed::toInt(void) const
{
	return this->_fixedPointValue >> Fixed::_fractionalBits;
}

float	Fixed::toFloat(void) const
{
	return this->_fixedPointValue / static_cast<float>(1 << Fixed::_fractionalBits);
}

Fixed& Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPointValue = raw;
}

std::ostream &operator<<(std::ostream &os, Fixed const &other)
{
	os << other.toFloat();
	return os;
}

const int	Fixed::_fractionalBits = 8;
