#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Form
{
	private:
		std::string const	_name;
		bool				_isSigned;
		uint8_t const		_gradeToSign;
		uint8_t const		_gradeToExecute;
	public:
		Form();
		Form( std::string const& name, int const& gradeToSign, int const& gradeToExecute );
		Form( Form const &other );
		Form&	operator=( Form const &other );
		~Form();

		std::string const&	getName() const;
		bool				isSigned() const;
		uint8_t const&		getGradeToSign() const;
		uint8_t const&		getGradeToExecute() const;
};

std::ostream& operator<<( std::ostream& os, Bureaucrat const& other );

#endif