#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define ANIMALS_AMOUNT 2

int main()
{
	{
		std::cout << "\nShould not leak.\n------------------------------------" << std::endl;
		Animal*	animals[ANIMALS_AMOUNT];
		for (size_t i = 0; i < ANIMALS_AMOUNT; i++)
		{
			if (i < ANIMALS_AMOUNT / 2)
			{
				animals[i] = new Dog();
			}
			else
			{
				animals[i] = new Cat();
			}
			animals[i]->makeSound();
			delete animals[i];
		}
	}
	{
		std::cout << "\nCheck deep copying with copy constructor\n------------------------------------" << std::endl;
		Cat*	cat1 = new Cat();
		Cat*	cat2 = new Cat(*cat1);
		std::cout << cat1->getBrain() << std::endl;
		std::cout << cat2->getBrain() << std::endl;
		delete cat1;
		delete cat2;
	}
	{
		std::cout << "\nCheck deep copying with assignment operator\n------------------------------------" << std::endl;
		Cat*	cat1 = new Cat();
		Cat*	cat2 = new Cat();
		std::cout << cat1->getBrain() << std::endl;
		std::cout << cat2->getBrain() << std::endl;
		*cat2 = *cat1;
		std::cout << cat1->getBrain() << std::endl;
		std::cout << cat2->getBrain() << std::endl;
		delete cat1;
		delete cat2;
	}
return 0;
}