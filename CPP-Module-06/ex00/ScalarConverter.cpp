#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &) {}
ScalarConverter & ScalarConverter::operator=(ScalarConverter const &) { return *this; }
ScalarConverter::~ScalarConverter() {}

// ---- Type detection ----

bool ScalarConverter::isChar(std::string const & s)
{
	// 'c' format: exactly 3 chars, first and last are single quotes
	return s.length() == 3 && s[0] == '\'' && s[2] == '\'';
}

bool ScalarConverter::isInt(std::string const & s)
{
	if (s.empty()) return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') ++i;
	if (i == s.length()) return false;
	for (; i < s.length(); ++i)
		if (s[i] < '0' || s[i] > '9') return false;
	return true;
}

bool ScalarConverter::isFloat(std::string const & s)
{
	if (s.empty() || s[s.length() - 1] != 'f') return false;
	std::string withoutF = s.substr(0, s.length() - 1);
	if (withoutF.empty()) return false;
	size_t i = 0;
	if (withoutF[i] == '+' || withoutF[i] == '-') ++i;
	bool hasDot = false;
	bool hasDigit = false;
	for (; i < withoutF.length(); ++i) {
		if (withoutF[i] == '.') {
			if (hasDot) return false;
			hasDot = true;
		} else if (withoutF[i] >= '0' && withoutF[i] <= '9') {
			hasDigit = true;
		} else {
			return false;
		}
	}
	return hasDot && hasDigit;
}

bool ScalarConverter::isDouble(std::string const & s)
{
	if (s.empty()) return false;
	size_t i = 0;
	if (s[i] == '+' || s[i] == '-') ++i;
	bool hasDot = false;
	bool hasDigit = false;
	for (; i < s.length(); ++i) {
		if (s[i] == '.') {
			if (hasDot) return false;
			hasDot = true;
		} else if (s[i] >= '0' && s[i] <= '9') {
			hasDigit = true;
		} else {
			return false;
		}
	}
	return hasDot && hasDigit;
}

bool ScalarConverter::isPseudoFloat(std::string const & s)
{
	return s == "-inff" || s == "+inff" || s == "nanf";
}

bool ScalarConverter::isPseudoDouble(std::string const & s)
{
	return s == "-inf" || s == "+inf" || s == "nan";
}

// ---- Print helpers ----

static void printChar(double d)
{
	if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(d)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d)
{
	if (std::isnan(d) || std::isinf(d)
	    || d < static_cast<double>(std::numeric_limits<int>::min())
	    || d > static_cast<double>(std::numeric_limits<int>::max()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
	float f = static_cast<float>(d);
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(f))
		std::cout << "float: nanf" << std::endl;
	else if (std::isinf(f))
		std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;
}

static void printDouble(double d)
{
	std::cout << std::fixed << std::setprecision(1);
	if (std::isnan(d))
		std::cout << "double: nan" << std::endl;
	else if (std::isinf(d))
		std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}

// ---- Main convert ----

void ScalarConverter::convert(std::string const & s)
{
	double d = 0.0;

	if (isChar(s)) {
		d = static_cast<double>(s[1]);
	} else if (isInt(s)) {
		errno = 0;
		long l = std::strtol(s.c_str(), NULL, 10);
		if (errno != 0
		    || l < static_cast<long>(std::numeric_limits<int>::min())
		    || l > static_cast<long>(std::numeric_limits<int>::max())) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible (overflow)" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			return;
		}
		d = static_cast<double>(static_cast<int>(l));
	} else if (isFloat(s)) {
		d = static_cast<double>(std::strtof(s.c_str(), NULL));
	} else if (isPseudoFloat(s)) {
		if (s == "nanf")       d = std::numeric_limits<double>::quiet_NaN();
		else if (s == "+inff") d = std::numeric_limits<double>::infinity();
		else                   d = -std::numeric_limits<double>::infinity();
	} else if (isDouble(s)) {
		d = std::strtod(s.c_str(), NULL);
	} else if (isPseudoDouble(s)) {
		if (s == "nan")       d = std::numeric_limits<double>::quiet_NaN();
		else if (s == "+inf") d = std::numeric_limits<double>::infinity();
		else                  d = -std::numeric_limits<double>::infinity();
	} else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	printChar(d);
	printInt(d);
	printFloat(d);
	printDouble(d);
}
