#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

// #ifdef DEBUG
// 	static void	ice_tests()
// 	{
// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Ice - default constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Ice*	ice1 = new Ice();
// 			std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
// 			delete ice1;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Ice - parameterized constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Ice*	ice1 = new Ice("water");
// 			std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
// 			delete ice1;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Ice - copy constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Ice*	ice1 = new Ice("water1");
// 			Ice*	ice2 = new Ice(*ice1);
// 			std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
// 			std::cout << "ice2->getType(): " << ice2->getType() << std::endl;
// 			delete ice1;
// 			delete ice2;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Ice - copy assignment operator" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Ice*	ice1 = new Ice("water1");
// 			Ice*	ice2 = new Ice();
// 			std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
// 			std::cout << "ice2->getType(): " << ice2->getType() << std::endl;
// 			*ice2 = *ice1;
// 			std::cout << "ice1->getType(): " << ice1->getType() << std::endl;
// 			std::cout << "ice2->getType(): " << ice2->getType() << std::endl;
// 			delete ice1;
// 			delete ice2;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Ice - clone function" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Ice*		ice1 = new Ice();
// 			AMateria*	materia;
// 			materia = ice1->clone();
// 			std::cout << "ice1: " << &ice1 << std::endl;
// 			delete ice1;
// 			std::cout << "materia: " << &materia << std::endl;
// 			delete materia;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Ice - use function" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Ice*		ice1 = new Ice();
// 			ICharacter* bob = new Character("Bob");
// 			ice1->use(*bob);
// 			delete ice1;
// 			delete bob;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}
// 	}

// 	static void	cure_tests()
// 	{
// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Cure - default constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Cure*	cure1 = new Cure();
// 			std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
// 			delete cure1;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Cure - parameterized constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Cure*	cure1 = new Cure("water");
// 			std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
// 			delete cure1;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Cure - copy constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Cure*	cure1 = new Cure("water1");
// 			Cure*	cure2 = new Cure(*cure1);
// 			std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
// 			std::cout << "cure2->getType(): " << cure2->getType() << std::endl;
// 			delete cure1;
// 			delete cure2;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Cure - copy assignment operator" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Cure*	cure1 = new Cure("water1");
// 			Cure*	cure2 = new Cure();
// 			std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
// 			std::cout << "cure2->getType(): " << cure2->getType() << std::endl;
// 			*cure2 = *cure1;
// 			std::cout << "cure1->getType(): " << cure1->getType() << std::endl;
// 			std::cout << "cure2->getType(): " << cure2->getType() << std::endl;
// 			delete cure1;
// 			delete cure2;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Cure - clone function" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Cure*		cure1 = new Cure();
// 			AMateria*	materia;
// 			materia = cure1->clone();
// 			std::cout << "cure1: " << &cure1 << std::endl;
// 			delete cure1;
// 			std::cout << "materia: " << &materia << std::endl;
// 			delete materia;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Cure - use function" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			Cure*		cure1 = new Cure();
// 			ICharacter* bob = new Character("Bob");
// 			cure1->use(*bob);
// 			delete cure1;
// 			delete bob;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}
// 	}

// 	static void character_testes()
// 	{
// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Character - default constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			ICharacter* character = new Character();
// 			std::cout << "character->getName(): " << character->getName() << std::endl;
// 			delete character;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Character - parameterized constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			ICharacter* bob = new Character("Bob");
// 			std::cout << "bob->getName(): " << bob->getName() << std::endl;
// 			delete bob;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Character - copy constructor" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			IMateriaSource* src = new MateriaSource();
// 			src->learnMateria(new Ice());
// 			src->learnMateria(new Cure());
// 			Character*	character1 = new Character();
// 			AMateria* tmp;
// 			tmp = src->createMateria("ice");
// 			character1->equip(tmp);
// 			tmp = src->createMateria("cure");
// 			character1->equip(tmp);
// 			Character*	character2 = new Character(*character1);
// 			character2->unequip(0);
// 			character2->unequip(1);
// 			delete character1;
// 			delete character2;
// 			delete src;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Character - copy assignment operator" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			IMateriaSource* src = new MateriaSource();
// 			src->learnMateria(new Ice());
// 			src->learnMateria(new Cure());
// 			Character*	character1 = new Character();
// 			AMateria* tmp;
// 			tmp = src->createMateria("ice");
// 			character1->equip(tmp);
// 			tmp = src->createMateria("cure");
// 			character1->equip(tmp);
// 			Character*	character2 = new Character();
// 			*character2 = *character1;
// 			character2->unequip(0);
// 			character2->unequip(1);
// 			delete character1;
// 			delete character2;
// 			delete src;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}

// 		{
// 			std::cout << "---------------------------" << std::endl;
// 			std::cout << "Character - use/equip/unequip functions" << std::endl;
// 			std::cout << "---------------------------" << std::endl;
// 			IMateriaSource* src = new MateriaSource();
// 			src->learnMateria(new Ice());
// 			Character*	character1 = new Character();
// 			AMateria* tmp;
// 			tmp = src->createMateria("ice");
// 			character1->equip(tmp);
// 			character1->use(0, *character1);
// 			character1->unequip(0);
// 			character1->use(0, *character1);
// 			delete src;
// 			delete character1;
// 			std::cout << "---------------------------\n" << std::endl;
// 		}
// 	}
// #endif

int main()
{
	// #ifdef DEBUG
	// 	ice_tests();
	// 	cure_tests();
	// 	character_testes();
	// #endif

	// {
	// 	MateriaSource* materiaSource1 = new MateriaSource();
	// 	materiaSource1->learnMateria(new Ice());
	// 	materiaSource1->learnMateria(new Ice());
	// 	materiaSource1->learnMateria(new Ice());
	// 	materiaSource1->learnMateria(new Ice());
	// 	MateriaSource* materiaSource2 = new MateriaSource();
	// 	*materiaSource2 = *materiaSource1;
	// 	delete materiaSource1;
	// 	delete materiaSource2;
	// }

	{
		MateriaSource* materiaSource1 = new MateriaSource();
		materiaSource1->learnMateria(new Ice());
		materiaSource1->learnMateria(new Cure());
		MateriaSource* materiaSource2 = new MateriaSource(*materiaSource1);
		delete materiaSource1;
		delete materiaSource2;
	}

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