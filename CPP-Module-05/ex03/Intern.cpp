#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(Intern const &)
{
}

Intern & Intern::operator=(Intern const &)
{
	return *this;
}

Intern::~Intern()
{
}

AForm * Intern::makeShrubbery(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

AForm * Intern::makeRobotomy(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

AForm * Intern::makePresidential(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

AForm * Intern::makeForm(std::string const & formName, std::string const & target) const
{
	struct FormEntry {
		std::string  name;
		FormCreator  creator;
	};

	FormEntry forms[] = {
		{ "shrubbery creation",    &Intern::makeShrubbery   },
		{ "robotomy request",      &Intern::makeRobotomy    },
		{ "presidential pardon",   &Intern::makePresidential }
	};

	int const count = 3;
	for (int i = 0; i < count; ++i) {
		if (forms[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}

	std::cerr << "Intern: Unknown form name: \"" << formName << "\"" << std::endl;
	return NULL;
}
