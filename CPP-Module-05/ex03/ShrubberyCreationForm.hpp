#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(std::string const & target);
	ShrubberyCreationForm(ShrubberyCreationForm const & other);
	ShrubberyCreationForm & operator=(ShrubberyCreationForm const & other);
	virtual ~ShrubberyCreationForm();

	virtual void executeAction() const;

private:
	std::string _target;
};

#endif
