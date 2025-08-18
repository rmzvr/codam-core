#include "Replace.hpp"

Replace::Replace
(
	std::string fileName
) :
	_postfix(".replace"),
	_fileName(fileName)
{
	this->_openInputFileStream();
	this->_openOutputFileStream();
}

Replace::~Replace
()
{
	this->_inFileStream.close();
	this->_outFileStream.close();
}

void Replace::_openInputFileStream()
{
	_inFileStream.open(_fileName.c_str());
	if (_inFileStream.fail())
	{
		throw std::runtime_error("Failed to open file.");
	}
}

void Replace::_openOutputFileStream()
{
	std::string	newFileName = _fileName + _postfix;

	_outFileStream.open(newFileName.c_str());
	if (_outFileStream.fail())
	{
		throw std::runtime_error("Failed to open file.");
	}
}

void	Replace::replace(
	std::string stringToReplace,
	std::string replacementString
)
{
	std::string	buffer;
	std::string	fileContentLine;
	std::size_t	currentFoundIndex;

	do
	{
		if (!std::getline(_inFileStream, fileContentLine))
		{
			if (_inFileStream.eof() == false)
				throw std::runtime_error("Failed to read file.");
			break;
		}
		if (_inFileStream.eof() == false)
			fileContentLine += '\n';
		buffer += fileContentLine;
		currentFoundIndex = buffer.find(stringToReplace);
		while (currentFoundIndex != std::string::npos)
		{
			std::string partBeforeFound = buffer.substr(0, currentFoundIndex);
			_outFileStream << partBeforeFound;
			buffer.erase(0, currentFoundIndex + stringToReplace.length());
			_outFileStream << replacementString;
			currentFoundIndex = buffer.find(stringToReplace);
		}
	} while (true);
	_outFileStream << buffer;
}
