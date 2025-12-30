#include "Dog.hpp"

Dog::Dog() : _brain(new Brain())
{
	_type = "Dog";
	std::cout << "Dog: Default Constructor called." << std::endl;
}

Dog::Dog(const Dog& copy) : Animal(copy), _brain(new Brain(*(copy._brain)))
{
	std::cout << "Dog: Copy Constructor called." << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	std::cout << "Dog: Copy Assingment Operator called." << std::endl;
	if (this != &copy)
	{
		Animal::operator=(copy);
		if (_brain)
			delete _brain;
		_brain = new Brain(*(copy._brain));
		_type = copy._type;
	}
	return (*this);
}

Dog::~Dog(void)
{
	delete _brain;
	std::cout << "Dog: Destructor called." << std::endl;
}

void Dog::makeSound(void) const
{
	std::cout << "Woof" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return (_brain);
}

void Dog::setBrain(Brain *brain)
{
	_brain = brain;
}
