#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}

	std::string input(argv[1]);
	std::cout << "Input: \"" << input << "\"" << std::endl;
	ScalarConverter::convert(input);
	std::cout << std::endl;

	// Additional tests
	const char* tests[] = {
		"0", "42", "-42", "42.0f", "-4.2f", "4.2",
		"nan", "nanf", "+inf", "-inf", "+inff", "-inff",
		"'a'", "'Z'", "0.0", NULL
	};

	for (int i = 0; tests[i] != NULL; ++i) {
		std::cout << "--- " << tests[i] << " ---" << std::endl;
		ScalarConverter::convert(std::string(tests[i]));
		std::cout << std::endl;
	}

	return 0;
}
