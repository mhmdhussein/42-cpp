#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
	Array<int> a(5);

	for (size_t i = 0; i < a.size(); i++)
		a[i] = i * 10;

	std::cout << "Array a: ";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	Array<int> b = a;
	b[0] = 999;

	std::cout << "Array a after copy: ";
	for (size_t i = 0; i < a.size(); i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	std::cout << "Array b: ";
	for (size_t i = 0; i < b.size(); i++)
		std::cout << b[i] << " ";
	std::cout << std::endl;

	Array<std::string> s(2);
	s[0] = "hello";
	s[1] = "world";

	std::cout << "String array: ";
	for (size_t i = 0; i < s.size(); i++)
		std::cout << s[i] << " ";
	std::cout << std::endl;

	try
	{
		std::cout << a[10] << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}
