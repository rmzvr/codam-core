#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0)
{
	#ifdef DEBUG
		std::cout << "Default constructor called" << std::endl;
	#endif
}

Fixed::Fixed(Fixed const &other)
{
	#ifdef DEBUG
		std::cout << "Copy constructor called" << std::endl;
	#endif
	*this = other;
}

Fixed::Fixed(int const int_number)
{
	#ifdef DEBUG
		std::cout << "Int constructor called" << std::endl;
	#endif
	this->_fixedPointValue = int_number << Fixed::_fractionalBits;
}

Fixed::Fixed(float const float_number)
{
	#ifdef DEBUG
		std::cout << "Float constructor called" << std::endl;
	#endif
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
	#ifdef DEBUG
		std::cout << "Copy assignment operator called" << std::endl;
	#endif
	if (this != &other)
	{
		this->_fixedPointValue = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed()
{
	#ifdef DEBUG
		std::cout << "Destructor called" << std::endl;
	#endif
}

int	Fixed::getRawBits() const
{
	#ifdef DEBUG
		std::cout << "getRawBits member function called" << std::endl;
	#endif
	return this->_fixedPointValue;
}

void	Fixed::setRawBits(int const raw)
{
	#ifdef DEBUG
		std::cout << "setRawBits member function called" << std::endl;
	#endif
	this->_fixedPointValue = raw;
}

const int	Fixed::_fractionalBits = 8;


Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed	fixed;
	int		result;

	result = this->getRawBits() + rhs.getRawBits();
	fixed.setRawBits(result);
	return fixed;
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed	fixed;
	int		result;

	result = this->getRawBits() - rhs.getRawBits();
	fixed.setRawBits(result);
	return fixed;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed	fixed;

	int64_t	lhs_raw = static_cast<int64_t>(this->getRawBits());
	int64_t	rhs_raw = static_cast<int64_t>(rhs.getRawBits());
	int		res_raw = (lhs_raw * rhs_raw) >> Fixed::_fractionalBits;

	fixed.setRawBits(res_raw);
	return fixed;
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	Fixed	fixed;

	if (rhs.getRawBits() == 0)
	{
		std::cout << "Nice try..." << std::endl;
		return fixed;
	}

	int64_t	lhs_raw = static_cast<int64_t>(this->getRawBits()) << Fixed::_fractionalBits;
	int		rhs_raw = rhs.getRawBits();
	int		res_raw = lhs_raw / rhs_raw;

	fixed.setRawBits(res_raw);
	return fixed;
}

bool Fixed::operator>(Fixed const &rhs)
{
	if (this->getRawBits() > rhs.getRawBits())
		return (true);
	return false;
}

bool Fixed::operator<(Fixed const &rhs)
{
	if (this->getRawBits() < rhs.getRawBits())
		return (true);
	return false;
}

bool Fixed::operator>=(Fixed const &rhs)
{
	if (this->getRawBits() >= rhs.getRawBits())
		return (true);
	return false;
}

bool Fixed::operator<=(Fixed const &rhs)
{
	if (this->getRawBits() <= rhs.getRawBits())
		return (true);
	return false;
}

bool Fixed::operator==(Fixed const &rhs)
{
	if (this->getRawBits() == rhs.getRawBits())
		return (true);
	return false;
}

bool Fixed::operator!=(Fixed const &rhs)
{
	if (this->getRawBits() != rhs.getRawBits())
		return (true);
	return false;
}

Fixed& Fixed::operator++( void )
{
	this->setRawBits(this->getRawBits() + 1);
	return *this;
}

Fixed Fixed::operator++( int )
{
	Fixed fixed = *this;
	this->setRawBits(this->getRawBits() + 1);
	return fixed;
}

std::ostream &operator<<(std::ostream &os, Fixed const &other)
{
	os << other.toFloat();
	return os;
}


Fixed & Fixed::min(Fixed & a, Fixed & b)
{
	if (a.getRawBits() < b.getRawBits())
	{
		return a;
	}
	return b;
}

Fixed const & Fixed::min(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() < b.getRawBits())
	{
		return a;
	}
	return b;
}

Fixed& Fixed::max(Fixed & a, Fixed & b)
{
	if (a.getRawBits() > b.getRawBits())
	{
		return a;
	}
	return b;
}

Fixed const & Fixed::max(Fixed const & a, Fixed const & b)
{
	if (a.getRawBits() > b.getRawBits())
	{
		return a;
	}
	return b;
}
