#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

int main()
{
	std::cout << "=== Test ex00: easyfind ===" << std::endl;

	// --- vector ---
	std::vector<int> vec;
	for (int i = 0; i < 10; ++i)
		vec.push_back(i * 3);  // 0, 3, 6, 9, 12, 15, 18, 21, 24, 27

	try {
		std::vector<int>::iterator it = easyfind(vec, 15);
		std::cout << "[vector] Found 15 at index "
		          << (it - vec.begin()) << std::endl;
	} catch (std::exception const & e) {
		std::cerr << "[vector] " << e.what() << std::endl;
	}

	try {
		easyfind(vec, 100);
	} catch (std::exception const & e) {
		std::cerr << "[vector] " << e.what() << std::endl;
	}

	// --- list ---
	std::list<int> lst;
	lst.push_back(42);
	lst.push_back(7);
	lst.push_back(99);
	lst.push_back(3);

	try {
		std::list<int>::iterator it = easyfind(lst, 99);
		std::cout << "[list]   Found 99: " << *it << std::endl;
	} catch (std::exception const & e) {
		std::cerr << "[list]   " << e.what() << std::endl;
	}

	try {
		easyfind(lst, 0);
	} catch (std::exception const & e) {
		std::cerr << "[list]   " << e.what() << std::endl;
	}

	// --- deque ---
	std::deque<int> dq;
	dq.push_back(10);
	dq.push_back(20);
	dq.push_back(30);

	try {
		std::deque<int>::iterator it = easyfind(dq, 20);
		std::cout << "[deque]  Found 20: " << *it << std::endl;
	} catch (std::exception const & e) {
		std::cerr << "[deque]  " << e.what() << std::endl;
	}

	// --- const container ---
	const std::vector<int> cvec(vec);
	try {
		std::vector<int>::const_iterator it = easyfind(cvec, 9);
		std::cout << "[const]  Found 9: " << *it << std::endl;
	} catch (std::exception const & e) {
		std::cerr << "[const]  " << e.what() << std::endl;
	}

	return 0;
}
