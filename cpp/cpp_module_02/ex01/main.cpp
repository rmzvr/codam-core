#include "Fixed.hpp"
#include <cmath>

void print_binary_32(unsigned int n) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main( void )
{
	// Fixed	a;
	Fixed	const b( 10 );
	// std::cout << 42.42f - 42 << std::endl;

	// Fixed	const c( 42.42f );
	// Fixed	const d( b );

	// a = Fixed( 1234.4321f );

	float	f = roundf(42.42f * 256) / 256;
	std::cout << f << std::endl;
	// printf("%f\n", f);
	// print_binary_32(t);

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;
	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return 0;
}