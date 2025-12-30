#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define ANIMALS_COUNT 10

int main()
{
	std::cout << "===============================" << std::endl;
	std::cout << "  BASIC ALLOCATION / DELETION  " << std::endl;
	std::cout << "===============================" << std::endl;

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "     ARRAY OF ANIMALS TEST     " << std::endl;
	std::cout << "===============================" << std::endl;

	Animal* animals[ANIMALS_COUNT];

	for (int idx = 0; idx < ANIMALS_COUNT / 2; idx++)
		animals[idx] = new Dog();

	for (int idx = ANIMALS_COUNT / 2; idx < ANIMALS_COUNT; idx++)
		animals[idx] = new Cat();

	for (int idx = 0; idx < ANIMALS_COUNT; idx++)
		delete animals[idx];

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "       DEEP COPY TEST (DOG)    " << std::endl;
	std::cout << "===============================" << std::endl;

	Dog originalDog;
	originalDog.getBrain()->setIdea(0, "I want a bone");

	Dog copiedDog(originalDog);
	copiedDog.getBrain()->setIdea(0, "I want two bones");

	std::cout << "Original Dog idea: "
			<< originalDog.getBrain()->getIdea(0) << std::endl;
	std::cout << "Copied Dog idea:   "
			<< copiedDog.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "    DEEP COPY TEST (CAT)       " << std::endl;
	std::cout << "===============================" << std::endl;

	Cat originalCat;
	originalCat.getBrain()->setIdea(0, "I rule the house");

	Cat assignedCat;
	assignedCat = originalCat;
	assignedCat.getBrain()->setIdea(0, "I rule the universe");

	std::cout << "Original Cat idea: "
			<< originalCat.getBrain()->getIdea(0) << std::endl;
	std::cout << "Assigned Cat idea: "
			<< assignedCat.getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl;
	std::cout << "===============================" << std::endl;
	std::cout << "        SOUND TEST             " << std::endl;
	std::cout << "===============================" << std::endl;

	const Animal* a = new Dog();
	const Animal* b = new Cat();

	std::cout << a->getType() << " says: ";
	a->makeSound();
	std::cout << b->getType() << " says: ";
	b->makeSound();

	delete a;
	delete b;

	std::cout << std::endl;
	std::cout << "======== END OF TESTS =========" << std::endl;

	return 0;
}
