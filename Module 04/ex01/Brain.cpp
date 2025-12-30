#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain: Default Constructor called." << std::endl;
}

Brain::Brain(const Brain& copy)
{
	*this = copy;
	std::cout << "Brain: Copy Constructor called." << std::endl;
}

Brain& Brain::operator=(const Brain& copy)
{
	if (this != &copy)
	{
		for (int i = 0; i < 100; ++i)
		{
			ideas[i] = copy.ideas[i];
		}
	}
	std::cout << "Brain: Assignment Operator called." << std::endl;
	return *this;
}

Brain::~Brain()
{
	std::cout << "Brain: Destructor called." << std::endl;
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
	{
		return ideas[index];
	}
	return "";
}

void Brain::setIdea(int index, const std::string& idea)
{
	if (index >= 0 && index < 100)
	{
		ideas[index] = idea;
	}
}
