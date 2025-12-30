#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>

class PhoneBook
{
	private:
		Contact _contacts[8];
		int _nextIndex;
		int _count;
		static std::string formatCell(const std::string &s);

	public:
		PhoneBook();
		void addContact(const Contact &c);
		void displayTable() const;
		void displayContact(int index) const;
		int  size() const;
		bool validIndex(int index) const;
};

#endif
