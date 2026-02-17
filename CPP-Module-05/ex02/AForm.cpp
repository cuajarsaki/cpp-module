#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string const & name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const & other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

AForm & AForm::operator=(AForm const & other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm()
{
}

std::string const & AForm::getName()        const { return _name; }
bool                AForm::getSigned()      const { return _signed; }
int                 AForm::getGradeToSign() const { return _gradeToSign; }
int                 AForm::getGradeToExec() const { return _gradeToExec; }

void AForm::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!_signed)
		throw NotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	executeAction();
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

const char * AForm::NotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream & operator<<(std::ostream & os, AForm const & f)
{
	os << "AForm: " << f.getName()
	   << ", signed: " << (f.getSigned() ? "yes" : "no")
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to exec: " << f.getGradeToExec();
	return os;
}
