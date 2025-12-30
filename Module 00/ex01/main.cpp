#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

static bool getline_prompt(const std::string &prompt, std::string &out)
{
	std::cout << prompt;
	if (!std::getline(std::cin, out))
	{
		std::cout << std::endl;
		return false;
	}
	return true;
}

static std::string prompt_non_empty(const std::string &prompt)
{
	std::string s;
	while (true)
	{
		if (!getline_prompt(prompt, s))
			std::exit(0);
		if (!s.empty()) return s;
		std::cout << "Field cannot be empty. Try again." << std::endl;
	}
}

static void do_add(PhoneBook &pb)
{
	Contact c;
	c.setFirstName(prompt_non_empty("First name: "));
	c.setLastName(prompt_non_empty("Last name: "));
	c.setNickname(prompt_non_empty("Nickname: "));
	c.setPhoneNumber(prompt_non_empty("Phone number: "));
	c.setDarkestSecret(prompt_non_empty("Darkest secret: "));
	pb.addContact(c);
	std::cout << "Contact saved" << std::endl;
}

static void do_search(const PhoneBook &pb)
{
	if (pb.size() == 0)
	{
		std::cout << "PhoneBook is empty." << std::endl;
		return;
	}
	pb.displayTable();
	std::string input;
	if (!getline_prompt("Enter index to display: ", input))
		return;
	for (std::size_t i = 0; i < input.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(input[i])))
		{
			std::cout << "Invalid index" << std::endl;
			return;
		}
	}
	int idx = std::atoi(input.c_str());
	pb.displayContact(idx);
}

int main(void)
{
	PhoneBook pb;
	std::string cmd;

	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, cmd))
		{
			std::cout << std::endl;
			break;
		}
		if (cmd == "ADD") {
			do_add(pb);
		} else if (cmd == "SEARCH") {
			do_search(pb);
		} else if (cmd == "EXIT") {
			break;
		} else if (cmd.empty()) {
			continue;
		} else {
			continue;
		}
	}
	return 0;
}
