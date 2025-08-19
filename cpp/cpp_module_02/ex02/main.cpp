#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) / Fixed( 0 ) );

	// std::cout << a << " > " << b << " = " << ((a > b) ? "true": "false") << std::endl;
	// std::cout << a << " < " << b << " = " << ((a < b) ? "true": "false") << std::endl;
	// std::cout << a << " >= " << b << " = " << ((a >= b) ? "true": "false") << std::endl;
	// std::cout << a << " <= " << b << " = " << ((a <= b) ? "true": "false") << std::endl;
	// std::cout << a << " == " << b << " = " << ((a == b) ? "true": "false") << std::endl;
	// std::cout << a << " != " << b << " = " << ((a != b) ? "true": "false") << std::endl;
	// std::cout << a << " + " << b << " = " << (a + b) << std::endl;
	// std::cout << a << " - " << b << " = " << (a - b) << std::endl;
	// std::cout << a << " * " << b << " = " << (a * b) << std::endl;
	// std::cout << a << " / " << b << " = " << (a / b) << std::endl;

	std::cout.precision(9);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}