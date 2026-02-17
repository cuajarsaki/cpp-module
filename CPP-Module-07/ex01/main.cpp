#include <iostream>
#include <string>
#include "iter.hpp"

// Print any type
template <typename T>
void printElem(T const & elem)
{
	std::cout << elem << " ";
}

// Double an int
void doubleIt(int & n)
{
	n *= 2;
}

// Uppercase a char
void toUpper(char & c)
{
	if (c >= 'a' && c <= 'z')
		c = static_cast<char>(c - 32);
}

int main()
{
	std::cout << "=== Test ex01: iter ===" << std::endl;

	// int array
	int arr[] = { 1, 2, 3, 4, 5 };
	std::cout << "Before double: ";
	::iter(arr, 5, printElem<int>);
	std::cout << std::endl;

	::iter(arr, 5, doubleIt);
	std::cout << "After  double: ";
	::iter(arr, 5, printElem<int>);
	std::cout << std::endl;

	// char array
	char chars[] = { 'h', 'e', 'l', 'l', 'o' };
	std::cout << "Before upper: ";
	::iter(chars, 5, printElem<char>);
	std::cout << std::endl;

	::iter(chars, 5, toUpper);
	std::cout << "After  upper: ";
	::iter(chars, 5, printElem<char>);
	std::cout << std::endl;

	// const array (read-only)
	const std::string strs[] = { "foo", "bar", "baz" };
	std::cout << "Const strings: ";
	::iter(strs, 3, printElem<std::string>);
	std::cout << std::endl;

	// function template as third param
	double dbl[] = { 1.1, 2.2, 3.3 };
	std::cout << "Doubles: ";
	::iter(dbl, 3, printElem<double>);
	std::cout << std::endl;

	return 0;
}
