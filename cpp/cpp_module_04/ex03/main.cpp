#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	// ICharacter* me = new Character("me");
	// Ice*	ice1 = new Ice();
	// Cure*	cure1 = new Cure();

	// std::cout << ice1->getType() << std::endl;
	// std::cout << cure1->getType() << std::endl;

	// ice1->use(*me);
	// cure1->use(*me);
	// AMateria*	ice2;
	// ice2 = ice1->clone();

	// AMateria*	cure2;
	// cure2 = cure1->clone();

	// std::cout << ice2->getType() << std::endl;
	// std::cout << cure2->getType() << std::endl;



	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}