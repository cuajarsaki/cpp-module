#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <limits>
# include <cmath>
# include <cerrno>
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
public:
	static void convert(std::string const & literal);

private:
	ScalarConverter();
	ScalarConverter(ScalarConverter const & other);
	ScalarConverter & operator=(ScalarConverter const & other);
	~ScalarConverter();

	// Type detection helpers
	static bool isChar(std::string const & s);
	static bool isInt(std::string const & s);
	static bool isFloat(std::string const & s);
	static bool isDouble(std::string const & s);
	static bool isPseudoFloat(std::string const & s);
	static bool isPseudoDouble(std::string const & s);

	// Output helpers
	static void printFromChar(char c);
	static void printFromInt(int n);
	static void printFromFloat(float f);
	static void printFromDouble(double d);
};

#endif
