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

		Fixed&					operator=( Fixed const & other );
		Fixed&					operator++( void );
		Fixed&					operator--( void );
		Fixed					operator++( int );
		Fixed					operator--( int );

		Fixed					operator+( Fixed const & rhs ) const;
		Fixed					operator-( Fixed const & rhs ) const;
		Fixed					operator*( Fixed const & rhs ) const;
		Fixed					operator/( Fixed const & rhs ) const;
		
		bool					operator>( Fixed const & rhs );
		bool					operator<( Fixed const & rhs );
		bool					operator>=( Fixed const & rhs );
		bool					operator<=( Fixed const & rhs );
		bool					operator==( Fixed const & rhs );
		bool					operator!=( Fixed const & rhs );

		int						toInt( void ) const;
		float					toFloat( void ) const;

		int						getRawBits( void ) const;
		void					setRawBits( int const raw );

		static Fixed&			min( Fixed & a, Fixed & b );
		static Fixed const &	min( Fixed const & a, Fixed const & b );

		static Fixed &			max( Fixed & a, Fixed & b );
		static Fixed const &	max( Fixed const & a, Fixed const & b );
};

std::ostream& operator<<( std::ostream& os, Fixed const & other );

#endif


