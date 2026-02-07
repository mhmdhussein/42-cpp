#include "ScalarConverter.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <cmath>
#include <iomanip>

static bool isChar(const std::string & s)
{
	return (s.length() == 1 && !std::isdigit(s[0]));
}

void ScalarConverter::convert(const std::string & literal)
{
	double value;
	bool impossible = false;

	if (isChar(literal))
		value = static_cast<double>(literal[0]);
	else
	{
		char * end;
		value = std::strtod(literal.c_str(), &end);
		if (*end && *end != 'f')
			impossible = true;
	}

	// char
	std::cout << "char: ";
	if (impossible || std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else if (!std::isprint(static_cast<char>(value)))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

	// int
	std::cout << "int: ";
	if (impossible || std::isnan(value)
		|| value > std::numeric_limits<int>::max()
		|| value < std::numeric_limits<int>::min())
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	// float
	std::cout << "float: ";
	if (impossible)
		std::cout << "impossible" << std::endl;
	else
	{
		float f = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(1)
				  << f << "f" << std::endl;
	}

	// double
	std::cout << "double: ";
	if (impossible)
		std::cout << "impossible" << std::endl;
	else
	{
		std::cout << std::fixed << std::setprecision(1)
				  << value << std::endl;
	}
}
