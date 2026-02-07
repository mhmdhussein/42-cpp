#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void);
void identify(Base * p);
void identify(Base & p);

class D : public Base {};

int main()
{
	std::srand(std::time(NULL));

	std::cout << "=== Valid types (A, B, C) ===" << std::endl;

	for (int i = 0; i < 5; i++)
	{
		Base * obj = generate();

		std::cout << "Pointer identify: ";
		identify(obj);

		std::cout << "Reference identify: ";
		identify(*obj);

		delete obj;
		std::cout << "-----" << std::endl;
	}

	std::cout << std::endl;
	std::cout << "=== Invalid type (D) ===" << std::endl;

	D d;
	Base * basePtr = &d;

	std::cout << "Pointer identify: ";
	identify(basePtr);

	std::cout << "Reference identify: ";
	identify(*basePtr);

	return 0;
}
