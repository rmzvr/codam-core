#include "Point.hpp"

static Fixed	getArea(Point const a, Point const b, Point const c)
{
	Fixed	area = ABS((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2.0f);
	return area;
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	Fixed	triangleArea;
	Fixed	a1Area;
	Fixed	a2Area;
	Fixed	a3Area;
	Fixed	calculatedArea;

	triangleArea = getArea(a, b, c);
	a1Area = getArea(point, b, c);
	if (a1Area == 0)
		return false;

	a2Area = getArea(a, point, c);
	if (a2Area == 0)
		return false;

	a3Area = getArea(a, b, point);
	if (a3Area == 0)
		return false;

	calculatedArea = a1Area + a2Area + a3Area;
	if (triangleArea == calculatedArea)
		return true;

	return false;
}
