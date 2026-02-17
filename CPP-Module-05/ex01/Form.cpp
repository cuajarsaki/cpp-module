#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const & name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(Form const & other)
	: _name(other._name), _signed(other._signed),
	  _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec)
{
}

Form & Form::operator=(Form const & other)
{
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form()
{
}

std::string const & Form::getName() const        { return _name; }
bool                Form::getSigned() const       { return _signed; }
int                 Form::getGradeToSign() const  { return _gradeToSign; }
int                 Form::getGradeToExec() const  { return _gradeToExec; }

void Form::beSigned(Bureaucrat const & b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char * Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream & operator<<(std::ostream & os, Form const & f)
{
	os << "Form: " << f.getName()
	   << ", signed: " << (f.getSigned() ? "yes" : "no")
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to exec: " << f.getGradeToExec();
	return os;
}
