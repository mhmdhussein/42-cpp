#include "Cat.hpp"

Cat::Cat() : _brain(new Brain())
{
	_type = "Cat";
	std::cout << "Cat: Default Constructor called." << std::endl;
}

Cat::Cat(const Cat& copy) : Animal(copy), _brain(new Brain(*(copy._brain)))
{
	std::cout << "Cat: Copy Constructor called." << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	std::cout << "Cat: Copy Assingment Operator called." << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		if (_brain)
			delete _brain;
		_brain = new Brain(*(copy._brain));
		_type = copy._type;
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat: Destructor called." << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return (_brain);
}

void Cat::setBrain(Brain *brain)
{
	_brain = brain;
}
