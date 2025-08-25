#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <iostream>

class ICharacter;

# define MAX_MATERIAS_AMOUNT 4

class AMateria
{
	protected:
		std::string	_type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& );
		virtual ~AMateria();

		std::string const &	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif