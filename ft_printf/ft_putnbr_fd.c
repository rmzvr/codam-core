#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;
	long	number;

	number = n;
	if (number < 0)
	{
		number = number * -1;
		write(fd, "-", 1);
	}
	if (number > 9)
	{
		ft_putnbr_fd(number / 10, fd);
	}
	digit = number % 10 + '0';
	write(fd, &digit, 1);
}