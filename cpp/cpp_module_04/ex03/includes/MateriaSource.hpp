#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include <iostream>
# include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource();
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	private:
		AMateria*		_materias[MAX_MATERIAS_AMOUNT];
		AMateria**		_clonedMaterias;
		unsigned int	_materiasAmount;
		unsigned int	_clonedMateriasAmount;
		unsigned int	_clonedMateriasMaxAmount;
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& other);
		MateriaSource& operator=(const MateriaSource& other);
		~MateriaSource();

		void		learnMateria(AMateria*);
		AMateria*	createMateria(std::string const & type);
};

#endif