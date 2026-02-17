#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {}

// Randomly instantiate A, B, or C
Base * generate(void)
{
	int r = std::rand() % 3;
	if (r == 0) return new A();
	if (r == 1) return new B();
	return new C();
}

// Identify via pointer: dynamic_cast returns NULL on failure
void identify(Base * p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "unknown" << std::endl;
}

// Identify via reference: dynamic_cast throws std::bad_cast on failure
// (no pointer allowed inside this function)
void identify(Base & p)
{
	try {
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (...) {}
	std::cout << "unknown" << std::endl;
}
