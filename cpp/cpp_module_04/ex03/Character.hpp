#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
// # include "AMateria.hpp"

# define MAX_MATERIAS_AMOUNT 4

class AMateria;

class ICharacter
{
	public:
		virtual ~ICharacter();
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class Character : public ICharacter
{
	private:
		std::string		_name;
		AMateria*		_materias[MAX_MATERIAS_AMOUNT];
		unsigned int	_materiasAmount;
	public:
		Character( std::string const & name );
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
