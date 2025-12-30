#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMALS_COUNT 10

int main()
{
	std::cout << "===============================" << std::endl;
	std::cout << "   ABSTRACT CLASS VALIDATION   " << std::endl;
	std::cout << "===============================" << std::endl;

	// Animal test;

	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "     ARRAY OF ABSTRACT BASE    " << std::endl;
	std::cout << "===============================" << std::endl;

	Animal* animals[ANIMALS_COUNT];

	for (int i = 0; i < ANIMALS_COUNT / 2; i++)
		animals[i] = new Dog();

	for (int i = ANIMALS_COUNT / 2; i < ANIMALS_COUNT; i++)
		animals[i] = new Cat();

	for (int i = 0; i < ANIMALS_COUNT; i++)
		animals[i]->makeSound();

	for (int i = 0; i < ANIMALS_COUNT; i++)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "        DEEP COPY TEST         " << std::endl;
	std::cout << "===============================" << std::endl;

	Dog basicDog;
	basicDog.getBrain()->setIdea(0, "Chasing cats");

	Dog copiedDog(basicDog);
	copiedDog.getBrain()->setIdea(0, "Sleeping");

	std::cout << "Basic Dog idea:  "
			  << basicDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea: "
			  << copiedDog.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "   POLYMORPHIC DELETION TEST   " << std::endl;
	std::cout << "===============================" << std::endl;

	const Animal* a = new Dog();
	delete a;

	std::cout << std::endl;
	std::cout << "======== END OF TESTS =========" << std::endl;

	return 0;
}
