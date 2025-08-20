#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed c( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "Comparison operators\n---------------------\n";
	std::cout << "1) " << a << " > " << b << " = " << ((a > b) ? "true": "false") << std::endl;
	std::cout << "2) " << a << " < " << b << " = " << ((a < b) ? "true": "false") << std::endl;
	std::cout << "3) " << c << " >= " << b << " = " << ((c >= b) ? "true": "false") << std::endl;
	std::cout << "4) " << a << " <= " << b << " = " << ((a <= b) ? "true": "false") << std::endl;
	std::cout << "5) " << c << " == " << b << " = " << ((c == b) ? "true": "false") << std::endl;
	std::cout << "6) " << a << " != " << b << " = " << ((a != b) ? "true": "false") << std::endl;
	std::cout << "---------------------\n\n";

	std::cout << "Arithmetic operators\n---------------------\n";
	std::cout << "1) " << a << " + " << b << " = " << (a + b) << std::endl;
	std::cout << "2) " << a << " - " << b << " = " << (a - b) << std::endl;
	std::cout << "3) " << c << " * " << b << " = " << (c * b) << std::endl;
	std::cout << "4) " << c << " / " << 0 << " = " << (c / 0) << std::endl;
	std::cout << "---------------------\n\n";

	std::cout.precision(9);
	std::cout << "Increment operators\n---------------------\n";
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "---------------------\n\n";

	std::cout << "Decrement operators\n---------------------\n";
	std::cout << "a: " << a << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "---------------------\n\n";


	std::cout << "Min function\n---------------------\n";
	std::cout << "min(c, b)\n" << "c: " << c << "\nb: " << b << "\n" << "result: " << Fixed::min( c, b ) << std::endl;
	std::cout << "\nmin(a, b)\n" << "a: " << a << "\nb: " << b << "\n" << "result: " << Fixed::min( a, b ) << std::endl;
	std::cout << "---------------------\n\n";

	std::cout << "Max function\n---------------------\n";
	std::cout << "max(c, b)\n" << "c: " << c << "\nb: " << b << "\n" << "result: " << Fixed::max( c, b ) << std::endl;
	std::cout << "\nmax(a, b)\n" << "a: " << a << "\nb: " << b << "\n" << "result: " << Fixed::max( a, b ) << std::endl;
	std::cout << "---------------------\n\n";
	return 0;
}