#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: ShrubberyCreationForm ===" << std::endl;
	try {
		Bureaucrat bob("Bob", 137);
		ShrubberyCreationForm shrub("home");

		std::cout << bob << std::endl;
		std::cout << shrub << std::endl;

		bob.signForm(shrub);
		bob.executeForm(shrub);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: RobotomyRequestForm Success ===" << std::endl;
	try {
		Bureaucrat alice("Alice", 45);
		RobotomyRequestForm robot("Bender");

		std::cout << alice << std::endl;
		std::cout << robot << std::endl;

		alice.signForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
		alice.executeForm(robot);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: PresidentialPardonForm ===" << std::endl;
	try {
		Bureaucrat president("President", 5);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << president << std::endl;
		std::cout << pardon << std::endl;

		president.signForm(pardon);
		president.executeForm(pardon);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Execute Unsigned Form ===" << std::endl;
	try {
		Bureaucrat charlie("Charlie", 1);
		ShrubberyCreationForm shrub2("garden");

		std::cout << charlie << std::endl;
		std::cout << shrub2 << std::endl;

		charlie.executeForm(shrub2);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Grade Too Low to Sign ===" << std::endl;
	try {
		Bureaucrat lowGrade("LowGrade", 150);
		PresidentialPardonForm pardon2("Ford Prefect");

		std::cout << lowGrade << std::endl;
		std::cout << pardon2 << std::endl;

		lowGrade.signForm(pardon2);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Grade Too Low to Execute ===" << std::endl;
	try {
		Bureaucrat signer("Signer", 25);
		Bureaucrat executor("Executor", 10);
		PresidentialPardonForm pardon3("Zaphod");

		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << pardon3 << std::endl;

		signer.signForm(pardon3);
		executor.executeForm(pardon3);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Complete Workflow ===" << std::endl;
	try {
		Bureaucrat boss("Boss", 1);

		ShrubberyCreationForm shrub3("office");
		RobotomyRequestForm robot2("Marvin");
		PresidentialPardonForm pardon4("Trillian");

		std::cout << boss << std::endl;

		boss.signForm(shrub3);
		boss.executeForm(shrub3);

		boss.signForm(robot2);
		boss.executeForm(robot2);

		boss.signForm(pardon4);
		boss.executeForm(pardon4);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
