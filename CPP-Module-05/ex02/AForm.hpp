#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm
{
public:
	AForm(std::string const & name, int gradeToSign, int gradeToExec);
	AForm(AForm const & other);
	AForm & operator=(AForm const & other);
	virtual ~AForm();

	std::string const & getName()        const;
	bool                getSigned()      const;
	int                 getGradeToSign() const;
	int                 getGradeToExec() const;

	void beSigned(Bureaucrat const & b);
	void execute(Bureaucrat const & executor) const;

	virtual void executeAction() const = 0;

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

	class NotSignedException : public std::exception
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

std::ostream & operator<<(std::ostream & os, AForm const & f);

#endif
