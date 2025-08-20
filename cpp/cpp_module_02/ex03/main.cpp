#include "Point.hpp"

int main( void ) {
	Point const	pointA(0.0f, 0.0f);
	Point const	pointB(10.0f, 30.0f);
	Point const	pointC(20.0f, 0.0f);
	Point const	pointP(10.0f, 0.0f);

	std::cout << bsp(pointA, pointB, pointC, pointP) << std::endl;
	return 0;
}