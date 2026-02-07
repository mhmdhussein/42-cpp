#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Create Valid Form ===" << std::endl;
	try {
		Form form1("Tax Form", 50, 25);
		std::cout << form1 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Form Grade Too High ===" << std::endl;
	try {
		Form form2("Invalid Form", 0, 25);
		std::cout << form2 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Form Grade Too Low ===" << std::endl;
	try {
		Form form3("Invalid Form", 50, 151);
		std::cout << form3 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Bureaucrat Signs Form Successfully ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 30);
		Form form4("Contract", 50, 25);
		std::cout << bob << std::endl;
		std::cout << form4 << std::endl;
		bob.signForm(form4);
		std::cout << form4 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Bureaucrat Grade Too Low to Sign ===" << std::endl;
	try {
		Bureaucrat lowGrade("LowGrade", 100);
		Form form5("Important Document", 50, 25);
		std::cout << lowGrade << std::endl;
		std::cout << form5 << std::endl;
		lowGrade.signForm(form5);
		std::cout << form5 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Sign Already Signed Form ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 1);
		Form form6("License", 10, 5);
		std::cout << alice << std::endl;
		std::cout << form6 << std::endl;
		alice.signForm(form6);
		alice.signForm(form6);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Multiple Bureaucrats ===" << std::endl;
	try {
		Bureaucrat high("HighRank", 5);
		Bureaucrat low("LowRank", 140);
		Form form7("Permit", 100, 50);

		std::cout << high << std::endl;
		std::cout << low << std::endl;
		std::cout << form7 << std::endl;

		low.signForm(form7);
		high.signForm(form7);
		std::cout << form7 << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
