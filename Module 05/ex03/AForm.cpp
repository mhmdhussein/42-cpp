#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string & name, int gs, int ge)
	: _name(name), _signed(false), _gradeSign(gs), _gradeExec(ge)
{
	if (gs < 1 || ge < 1)
		throw GradeTooHighException();
	if (gs > 150 || ge > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm & o)
	: _name(o._name), _signed(o._signed),
	  _gradeSign(o._gradeSign), _gradeExec(o._gradeExec) {}

AForm & AForm::operator=(const AForm & o)
{
	if (this != &o)
		_signed = o._signed;
	return *this;
}

AForm::~AForm() {}

const std::string & AForm::getName() const { return _name; }
bool AForm::isSigned() const { return _signed; }
int AForm::getGradeSign() const { return _gradeSign; }
int AForm::getGradeExec() const { return _gradeExec; }

void AForm::beSigned(const Bureaucrat & b)
{
	if (b.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeExec)
		throw GradeTooLowException();
	executeAction();
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "grade too high";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "grade too low";
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return "form not signed";
}

std::ostream & operator<<(std::ostream & os, const AForm & f)
{
	os << f.getName()
	   << ", signed: " << (f.isSigned() ? "yes" : "no")
	   << ", grade sign: " << f.getGradeSign()
	   << ", grade exec: " << f.getGradeExec();
	return os;
}
