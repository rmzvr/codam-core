#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <string>
# include <fstream>
# include <iostream>
# include <stdexcept>

class Replace
{
	private:
		std::string		_postfix;
		std::string		_fileName;
		std::string		_stringToReplace;
		std::string		_replacementString;
		std::ifstream	_inFileStream;
		std::ofstream	_outFileStream;

		void	_openInputFileStream();
		void	_openOutputFileStream();
	public:
		Replace(std::string fileName);
		~Replace();

		void	replace(
			std::string stringToReplace,
			std::string replacementString
		);
};

#endif
