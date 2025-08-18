#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits;
	public:
		Fixed();
		Fixed(Fixed const &other);
		~Fixed();
		Fixed&	operator=(Fixed const &other);

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
};



#endif