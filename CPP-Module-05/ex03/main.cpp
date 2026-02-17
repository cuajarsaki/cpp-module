#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "=== Test ex03: Intern ===" << std::endl;

	Intern someRandomIntern;

	// Test case from the subject
	{
		std::cout << "\n--- makeForm: robotomy request ---" << std::endl;
		AForm * rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf) {
			std::cout << *rrf << std::endl;
			Bureaucrat b("Dr. X", 40);
			b.signForm(*rrf);
			b.executeForm(*rrf);
			delete rrf;
		}
	}

	// Test shrubbery creation
	{
		std::cout << "\n--- makeForm: shrubbery creation ---" << std::endl;
		AForm * scf = someRandomIntern.makeForm("shrubbery creation", "office");
		if (scf) {
			std::cout << *scf << std::endl;
			Bureaucrat b("Groundskeeper", 137);
			b.signForm(*scf);
			b.executeForm(*scf);
			delete scf;
		}
	}

	// Test presidential pardon
	{
		std::cout << "\n--- makeForm: presidential pardon ---" << std::endl;
		AForm * ppf = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
		if (ppf) {
			std::cout << *ppf << std::endl;
			Bureaucrat b("Zaphod", 1);
			b.signForm(*ppf);
			b.executeForm(*ppf);
			delete ppf;
		}
	}

	// Test unknown form
	{
		std::cout << "\n--- makeForm: unknown form ---" << std::endl;
		AForm * unknown = someRandomIntern.makeForm("coffee order", "Java");
		if (!unknown)
			std::cout << "Returned NULL as expected." << std::endl;
	}

	return 0;
}
