#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class Form
{
public:
	Form(std::string const & name, int gradeToSign, int gradeToExec);
	Form(Form const & other);
	Form & operator=(Form const & other);
	~Form();

	std::string const & getName()        const;
	bool                getSigned()      const;
	int                 getGradeToSign() const;
	int                 getGradeToExec() const;

	void beSigned(Bureaucrat const & b);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char * what() const throw();
	};

private:
	std::string const _name;
	bool              _signed;
	int const         _gradeToSign;
	int const         _gradeToExec;
};

std::ostream & operator<<(std::ostream & os, Form const & f);

#endif
