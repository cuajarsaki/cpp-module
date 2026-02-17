#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	Intern();
	Intern(Intern const & other);
	Intern & operator=(Intern const & other);
	~Intern();

	AForm * makeForm(std::string const & formName, std::string const & target) const;

private:
	// Function pointer array approach to avoid if/else chains
	typedef AForm * (*FormCreator)(std::string const &);

	static AForm * makeShrubbery(std::string const & target);
	static AForm * makeRobotomy(std::string const & target);
	static AForm * makePresidential(std::string const & target);
};

#endif
