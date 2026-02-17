#include <iostream>
#include "PmergeMe.hpp"

int main(int argc, char* argv[])
{
	if (argc < 2) {
		std::cerr << "Error: usage: ./PmergeMe n1 n2 n3 ..." << std::endl;
		return 1;
	}

	PmergeMe pm;
	try {
		pm.parseArgs(argc, argv);
		pm.sortAndDisplay();
	} catch (std::exception const & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}
