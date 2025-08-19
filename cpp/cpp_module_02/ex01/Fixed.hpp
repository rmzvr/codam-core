#ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath>
# include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits;
	public:
		Fixed();
		Fixed( Fixed const &other );
		Fixed( int const int_number );
		Fixed( float const float_number );
		~Fixed();
		Fixed&	operator=( Fixed const & other );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;
};

std::ostream& operator<<( std::ostream& os, Fixed const & other );

#endif


