#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

static void	ice_tests()
{
	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Ice - default constructor" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Ice*	ice1 = new Ice();
		std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
		delete ice1;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Ice - parameterized constructor" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Ice*	ice1 = new Ice("water");
		std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
		delete ice1;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Ice - copy constructor" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Ice*	ice1 = new Ice("water1");
		Ice*	ice2 = new Ice(*ice1);
		std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
		std::cout << "ice2->getType(): " << ice2->getType() << std::endl;
		delete ice1;
		delete ice2;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Ice - copy assignment operator" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Ice*	ice1 = new Ice("water1");
		Ice*	ice2 = new Ice();
		std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
		std::cout << "ice2->getType(): " << ice2->getType() << std::endl;
		*ice2 = *ice1;
		std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
		std::cout << "ice2->getType(): " << ice2->getType() << std::endl;
		delete ice1;
		delete ice2;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Ice - clone function" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Ice*		ice1 = new Ice();
		AMateria*	materia;
		materia = ice1->clone();
		std::cout << "ice1: " << &ice1 << std::endl;
		delete ice1;
		std::cout << "materia: " << &materia << std::endl;
		delete materia;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Ice - use function" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Ice*		ice1 = new Ice();
		ICharacter* bob = new Character("Bob");
		ice1->use(*bob);
		delete ice1;
		delete bob;
		std::cout << "---------------------------\n" << std::endl;
	}
}

static void	cure_tests()
{
	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Cure - default constructor" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Cure*	cure1 = new Cure();
		std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
		delete cure1;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Cure - parameterized constructor" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Cure*	cure1 = new Cure("water");
		std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
		delete cure1;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Cure - copy constructor" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Cure*	cure1 = new Cure("water1");
		Cure*	cure2 = new Cure(*cure1);
		std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
		std::cout << "cure2->getType(): " << cure2->getType() << std::endl;
		delete cure1;
		delete cure2;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Cure - copy assignment operator" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Cure*	cure1 = new Cure("water1");
		Cure*	cure2 = new Cure();
		std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
		std::cout << "cure2->getType(): " << cure2->getType() << std::endl;
		*cure2 = *cure1;
		std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
		std::cout << "cure2->getType(): " << cure2->getType() << std::endl;
		delete cure1;
		delete cure2;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Cure - clone function" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Cure*		cure1 = new Cure();
		AMateria*	materia;
		materia = cure1->clone();
		std::cout << "cure1: " << &cure1 << std::endl;
		delete cure1;
		std::cout << "materia: " << &materia << std::endl;
		delete materia;
		std::cout << "---------------------------\n" << std::endl;
	}

	{
		std::cout << "---------------------------" << std::endl;
		std::cout << "Cure - use function" << std::endl;
		std::cout << "---------------------------" << std::endl;
		Cure*		cure1 = new Cure();
		ICharacter* bob = new Character("Bob");
		cure1->use(*bob);
		delete cure1;
		delete bob;
		std::cout << "---------------------------\n" << std::endl;
	}
}

int main()
{
	ice_tests();
	cure_tests();
	// ICharacter* me = new Character("me");
	// Ice*	ice1 = new Ice();
	// Ice*	ice2(ice1);
	// std::cout << ice2->getType() << std::endl;

	// delete ice1;
	// delete ice2;
	// ice1->use(*me);
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



	// {
	// 	IMateriaSource* src = new MateriaSource();
	// 	src->learnMateria(new Ice());
	// 	src->learnMateria(new Cure());
	// 	ICharacter* me = new Character("me");
	// 	AMateria* tmp;
	// 	tmp = src->createMateria("ice");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// 	tmp = src->createMateria("cure");
	// 	me->equip(tmp);
	// 	ICharacter* bob = new Character("bob");
	// 	me->use(0, *bob);
	// 	me->use(1, *bob);
	// 	me->unequip(0);
	// 	me->unequip(1);
	// 	delete bob;
	// 	delete me;
	// 	delete src;
	// 	return 0;
	// }
}