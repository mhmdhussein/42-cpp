#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

int main()
{
	std::cout << "=== Test 1: Intern Creates ShrubberyCreationForm ===" << std::endl;
	try {
		Intern intern;
		AForm* form;

		form = intern.makeForm("shrubbery creation", "home");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 2: Intern Creates RobotomyRequestForm ===" << std::endl;
	try {
		Intern intern;
		AForm* form;

		form = intern.makeForm("robotomy request", "Bender");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 3: Intern Creates PresidentialPardonForm ===" << std::endl;
	try {
		Intern intern;
		AForm* form;

		form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 4: Invalid Form Name ===" << std::endl;
	try {
		Intern intern;
		AForm* form;

		form = intern.makeForm("invalid form", "Target");
		if (form) {
			std::cout << *form << std::endl;
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 5: Complete Workflow with Intern ===" << std::endl;
	try {
		Intern intern;
		Bureaucrat boss("Boss", 1);
		AForm* form;

		std::cout << boss << std::endl;

		form = intern.makeForm("robotomy request", "Employee");
		if (form) {
			std::cout << *form << std::endl;
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 6: Multiple Forms Created by Intern ===" << std::endl;
	try {
		Intern someRandomIntern;
		Bureaucrat ceo("CEO", 1);
		AForm* forms[3];

		forms[0] = someRandomIntern.makeForm("shrubbery creation", "garden");
		forms[1] = someRandomIntern.makeForm("robotomy request", "Robot");
		forms[2] = someRandomIntern.makeForm("presidential pardon", "Criminal");

		for (int i = 0; i < 3; i++) {
			if (forms[i]) {
				std::cout << *forms[i] << std::endl;
				ceo.signForm(*forms[i]);
				ceo.executeForm(*forms[i]);
				delete forms[i];
				std::cout << std::endl;
			}
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n=== Test 7: Case Sensitivity Test ===" << std::endl;
	try {
		Intern intern;
		AForm* form1;
		AForm* form2;

		form1 = intern.makeForm("ROBOTOMY REQUEST", "Target1");
		form2 = intern.makeForm("Robotomy Request", "Target2");

		if (form1) {
			std::cout << "Created with uppercase" << std::endl;
			delete form1;
		}
		if (form2) {
			std::cout << "Created with mixed case" << std::endl;
			delete form2;
		}
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
