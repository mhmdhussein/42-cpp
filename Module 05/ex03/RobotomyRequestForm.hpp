#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;

	protected:
		void executeAction() const;

	public:
		RobotomyRequestForm(const std::string & target);
		~RobotomyRequestForm();
};

#endif
