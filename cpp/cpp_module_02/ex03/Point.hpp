#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

# define ABS(a) ((a) * (((a) > 0) - ((a) < 0)))

class Point
{
	private:
		Fixed const	_x;
		Fixed const	_y;
	public:
		Point();
		~Point();
		Point( Point const &other );
		Point( float const x, float const y );
		Point&	operator=( Point const & other );

		Fixed const	getX() const;
		Fixed const	getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );

#endif
