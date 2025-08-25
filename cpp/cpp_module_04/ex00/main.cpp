#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* a = new Cat();
	// {
	// 	std::cout << "Should override based methods with derived ones.\n------------------------------------" << std::endl;
	// 	const Animal* meta = new Animal();
	// 	const Animal* j = new Dog();
	// 	const Animal* i = new Cat();
	// 	std::cout << meta->getType() << " " << std::endl;
	// 	std::cout << j->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound();
	// 	j->makeSound();
	// 	meta->makeSound();
	// 	std::cout << std::endl;
	// 	delete meta;
	// 	delete i;
	// 	delete j;
	// }
	// {
	// 	std::cout << "Shouldn't override based method makeSound() with derived one.\n------------------------------------" << std::endl;
	// 	const WrongAnimal* meta = new WrongAnimal();
	// 	const WrongAnimal* i = new WrongCat();
	// 	std::cout << meta->getType() << " " << std::endl;
	// 	std::cout << i->getType() << " " << std::endl;
	// 	i->makeSound();
	// 	meta->makeSound();
	// 	delete meta;
	// 	delete i;
	// }
return 0;
}