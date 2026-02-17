#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << "=== Test ex02: AForm + Concrete Forms ===" << std::endl;

	// Test ShrubberyCreationForm
	{
		std::cout << "\n--- ShrubberyCreationForm ---" << std::endl;
		Bureaucrat b("Gardener", 140);
		ShrubberyCreationForm f("home");
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
	}

	// Test RobotomyRequestForm
	{
		std::cout << "\n--- RobotomyRequestForm ---" << std::endl;
		Bureaucrat b("Dr. Robotomy", 40);
		RobotomyRequestForm f("Bender");
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
		b.executeForm(f);
		b.executeForm(f);
	}

	// Test PresidentialPardonForm
	{
		std::cout << "\n--- PresidentialPardonForm ---" << std::endl;
		Bureaucrat b("President", 1);
		PresidentialPardonForm f("Ford Prefect");
		std::cout << f << std::endl;
		b.signForm(f);
		b.executeForm(f);
	}

	// Test: execute without signing
	{
		std::cout << "\n--- Execute without signing ---" << std::endl;
		Bureaucrat b("Nobody", 1);
		PresidentialPardonForm f("Marvin");
		b.executeForm(f);
	}

	// Test: grade too low to execute
	{
		std::cout << "\n--- Grade too low to execute ---" << std::endl;
		Bureaucrat signer("Big Boss", 1);
		Bureaucrat lowGuy("Intern", 150);
		RobotomyRequestForm f("Zaphod");
		signer.signForm(f);
		lowGuy.executeForm(f);
	}

	return 0;
}
