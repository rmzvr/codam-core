#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	#ifdef DEBUG
		std::cout << "Default constructor called" << std::endl;
	#endif
}

Point::Point( float const x, float const y ) : _x(x), _y(y)
{
}

Point::Point( Point const &other ) : _x(other._x), _y(other._y)
{
	#ifdef DEBUG
		std::cout << "Copy constructor called" << std::endl;
	#endif
}

Point& Point::operator=(Point const &other)
{
	#ifdef DEBUG
		std::cout << "Copy assignment operator called" << std::endl;
	#endif
	(void) other;
	return *this;
}

Point::~Point()
{
	#ifdef DEBUG
		std::cout << "Destructor called" << std::endl;
	#endif
}

Fixed const	Point::getX() const
{
	return this->_x;
}

Fixed const	Point::getY() const
{
	return this->_y;
}