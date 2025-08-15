#include <iostream>
#include <fstream>

void	print(std::string message)
{
	std::cout << '"' << message << '"' << std::endl;
}

int	main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid amount of arguments." << std::endl;
		return 1;
	}
	std::ifstream	inFileStream;
	std::ofstream	outFileStream;
	std::string		line;
	std::string		buffer;
	std::string		fileContentLine;
	std::string		fileName = argv[1];
	std::string		s1 = argv[2];
	std::string		s2 = argv[3];
	// std::size_t		prevFoundIndex = 0;
	std::size_t		currFoundIndex;

	inFileStream.open(fileName);
	if (inFileStream.fail())
	{
		std::perror("Error");
		return 1;
	}
	outFileStream.open(fileName.append(".replace"));
	if (outFileStream.fail())
	{
		std::perror("Error");
		return 1;
	}
	do
	{
		if (!std::getline(inFileStream, line))
			break;
		line += '\n';
		buffer += line;
		currFoundIndex = buffer.find(s1);
		while (currFoundIndex != std::string::npos)
		{
			std::string partBeforeFound = buffer.substr(0, currFoundIndex);
			outFileStream << partBeforeFound;
			buffer.erase(0, currFoundIndex + s1.length());
			outFileStream << s2;
			currFoundIndex = buffer.find(s1);
		}
	} while (true);
	outFileStream << buffer;
	inFileStream.close();
	outFileStream.close();
	return 0;
}
