#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "===============================" << std::endl;
	std::cout << "     CORRECT POLYMORPHISM      " << std::endl;
	std::cout << "===============================" << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << std::endl;
	std::cout << i->getType() << std::endl;

	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "        WRONG POLYMORPHISM     " << std::endl;
	std::cout << "===============================" << std::endl;

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongMeta->getType() << std::endl;
	std::cout << wrongCat->getType() << std::endl;

	wrongMeta->makeSound();
	wrongCat->makeSound();

	delete wrongMeta;
	delete wrongCat;

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "        STACK OBJECT TEST     " << std::endl;
	std::cout << "===============================" << std::endl;

	Dog dog;
	Cat cat;

	dog.makeSound();
	cat.makeSound();

	std::cout << std::endl;
	std::cout << "======== END OF TESTS =========" << std::endl;

	return 0;
}
