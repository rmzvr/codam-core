#include <iostream>
#include <cctype>

int	main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; i < argc; ++i)
	{
		std::string str = argv[i];
		for (char c : str)
		{
			std::cout << (char) toupper(c);
		}
	}
	std::cout << std::endl;
	return (0);
}