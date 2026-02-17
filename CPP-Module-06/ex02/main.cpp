#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main()
{
	std::cout << "=== Test ex02: Identify real type ===" << std::endl;
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	for (int i = 0; i < 9; ++i) {
		Base * p = generate();

		std::cout << "via pointer : ";
		identify(p);

		std::cout << "via ref     : ";
		identify(*p);

		std::cout << std::endl;
		delete p;
	}

	// Manual tests to confirm each type
	std::cout << "--- Manual tests ---" << std::endl;
	{
		Base * a = new A();
		Base * b = new B();
		Base * c = new C();

		std::cout << "A ptr: "; identify(a);
		std::cout << "A ref: "; identify(*a);
		std::cout << "B ptr: "; identify(b);
		std::cout << "B ref: "; identify(*b);
		std::cout << "C ptr: "; identify(c);
		std::cout << "C ref: "; identify(*c);

		delete a;
		delete b;
		delete c;
	}

	return 0;
}
