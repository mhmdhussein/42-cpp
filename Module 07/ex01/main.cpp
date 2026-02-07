#include <iostream>
#include <string>
#include "iter.hpp"

void printInt(int & x)
{
	std::cout << x << " ";
}

void printConstInt(const int & x)
{
	std::cout << x << " ";
}

void toUpper(std::string & s)
{
	for (size_t i = 0; i < s.length(); i++)
		s[i] = std::toupper(s[i]);
}

void printString(const std::string & s)
{
	std::cout << s << " ";
}

int main()
{
	int nums[] = {1, 2, 3, 4};
	const int constNums[] = {5, 6, 7};

	std::string words[] = {"hello", "world"};

	std::cout << "Non-const int array: ";
	iter(nums, 4, printInt);
	std::cout << std::endl;

	std::cout << "Const int array: ";
	iter(constNums, 3, printConstInt);
	std::cout << std::endl;

	iter(words, 2, toUpper);

	std::cout << "Modified string array: ";
	iter(words, 2, printString);
	std::cout << std::endl;

	return 0;
}
