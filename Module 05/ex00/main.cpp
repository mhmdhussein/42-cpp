#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Valid Bureaucrat ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Grade Too High (0) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Grade Too Low (151) ===" << std::endl;
	try {
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Increment Grade ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 3);
		std::cout << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;
		alice.incrementGrade();
		std::cout << "After increment: " << alice << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Decrement Grade ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 148);
		std::cout << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie << std::endl;
		charlie.decrementGrade();
		std::cout << "After decrement: " << charlie << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Copy Constructor ===" << std::endl;
	try {
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Assignment Operator ===" << std::endl;
	try {
		Bureaucrat a("A", 100);
		Bureaucrat b("B", 50);
		std::cout << "Before assignment:" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
		a = b;
		std::cout << "After assignment (a = b):" << std::endl;
		std::cout << "a: " << a << std::endl;
		std::cout << "b: " << b << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
