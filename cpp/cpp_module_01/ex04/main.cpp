#include <iostream>
#include <fstream>
#include "Replace.hpp"

void	validate_arguments(int argc)
{
	if (argc != 4)
	{
		throw std::runtime_error("Invalid amount of arguments.\nUsage: ./replace [filename] [string_to_replace] [replacement_string]");
	}
}

int	main(int argc, char **argv)
{
	try
	{
		validate_arguments(argc);
		std::string		fileName = argv[1];
		std::string		stringToReplace = argv[2];
		std::string		replacementString = argv[3];
		Replace	searchAndReplace(fileName);
		searchAndReplace.replace(stringToReplace, replacementString);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
