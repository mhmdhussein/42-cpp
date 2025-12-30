#include "PhoneBook.hpp"
#include <iomanip>
#include <sstream>

PhoneBook::PhoneBook() : _nextIndex(0), _count(0) {}

void PhoneBook::addContact(const Contact &c)
{
	_contacts[_nextIndex] = c;
	_nextIndex = (_nextIndex + 1) % 8;
	if (_count < 8)
		_count++;
}

std::string PhoneBook::formatCell(const std::string &s)
{
	if (s.size() > 10)
		return s.substr(0, 9) + ".";
	std::ostringstream oss;
	oss << std::setw(10) << s;
	return oss.str();
}

void PhoneBook::displayTable() const
{
	std::cout << std::setw(10) << "Index" << "|"
			<< std::setw(10) << "First Name" << "|"
			<< std::setw(10) << "Last Name" << "|"
			<< std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < _count; i++)
	{
		const Contact &c = _contacts[i];
		std::cout << std::setw(10) << i << "|"
				<< formatCell(c.getFirstName()) << "|"
				<< formatCell(c.getLastName()) << "|"
				<< formatCell(c.getNickname()) << std::endl;
	}
}

void PhoneBook::displayContact(int index) const
{
	if (!validIndex(index))
	{
		std::cout << "Invalid index." << std::endl;
		return;
	}
	const Contact &c = _contacts[index];
	std::cout << "First name: " << c.getFirstName() << std::endl;
	std::cout << "Last name: " << c.getLastName() << std::endl;
	std::cout << "Nickname: " << c.getNickname() << std::endl;
	std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
	std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}

int PhoneBook::size() const
{
	return _count;
}

bool PhoneBook::validIndex(int index) const
{
	return index >= 0 && index < _count;
}
