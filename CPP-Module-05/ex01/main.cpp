#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "=== Test ex01: Form ===" << std::endl;

	// Normal form creation
	try {
		Form f("Form-A", 50, 25);
		std::cout << f << std::endl;

		Bureaucrat highGrade("Alice", 30);
		Bureaucrat lowGrade("Bob", 100);

		std::cout << highGrade << std::endl;
		std::cout << lowGrade << std::endl;

		lowGrade.signForm(f);   // should fail
		highGrade.signForm(f);  // should succeed
		highGrade.signForm(f);  // already signed (still works)
		std::cout << f << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Unexpected exception: " << e.what() << std::endl;
	}

	// Invalid form grade
	try {
		Form f("BadForm", 0, 10);
	} catch (std::exception & e) {
		std::cerr << "Exception (expected): " << e.what() << std::endl;
	}

	try {
		Form f("BadForm2", 10, 200);
	} catch (std::exception & e) {
		std::cerr << "Exception (expected): " << e.what() << std::endl;
	}

	return 0;
}
