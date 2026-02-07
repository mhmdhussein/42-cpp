#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	try
	{
		std::vector<int> v;
		for (int i = 0; i < 5; i++)
			v.push_back(i * 10);

		std::cout << "Vector test: ";
		std::vector<int>::iterator it = easyfind(v, 20);
		std::cout << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::list<int> l;
		l.push_back(1);
		l.push_back(2);
		l.push_back(3);

		std::cout << "List test: ";
		std::list<int>::iterator it = easyfind(l, 5);
		std::cout << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		std::deque<int> d;
		d.push_back(42);
		d.push_back(21);

		std::cout << "Deque test: ";
		std::deque<int>::iterator it = easyfind(d, 42);
		std::cout << *it << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
