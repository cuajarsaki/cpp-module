#include "Bureaucrat.hpp"

int main()
{
	std::cout << "=== Test ex00: Bureaucrat ===" << std::endl;

	// Normal creation
	try {
		Bureaucrat b("Alice", 42);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << "After increment: " << b << std::endl;
		b.decrementGrade();
		b.decrementGrade();
		std::cout << "After 2 decrements: " << b << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	// Grade too high
	try {
		Bureaucrat b("TooHigh", 0);
		std::cout << b << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception (expected): " << e.what() << std::endl;
	}

	// Grade too low
	try {
		Bureaucrat b("TooLow", 151);
		std::cout << b << std::endl;
	} catch (std::exception & e) {
		std::cerr << "Exception (expected): " << e.what() << std::endl;
	}

	// Increment past max
	try {
		Bureaucrat b("Bob", 1);
		std::cout << b << std::endl;
		b.incrementGrade();
	} catch (std::exception & e) {
		std::cerr << "Exception (expected): " << e.what() << std::endl;
	}

	// Decrement past min
	try {
		Bureaucrat b("Charlie", 150);
		std::cout << b << std::endl;
		b.decrementGrade();
	} catch (std::exception & e) {
		std::cerr << "Exception (expected): " << e.what() << std::endl;
	}

	return 0;
}
