#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain();
		~Brain();
		Brain( Brain const &other );
		Brain&	operator=( Brain const &other );
};

#endif