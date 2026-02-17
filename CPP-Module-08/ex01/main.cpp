#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main()
{
	std::cout << "=== Subject test ===" << std::endl;
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;  // 2
		std::cout << sp.longestSpan() << std::endl;   // 14
	}

	std::cout << "\n=== Exception tests ===" << std::endl;
	{
		Span sp(3);
		sp.addNumber(1);
		sp.addNumber(2);
		sp.addNumber(3);
		try {
			sp.addNumber(4);  // full
		} catch (std::exception const & e) {
			std::cerr << "Full: " << e.what() << std::endl;
		}

		Span sp1(1);
		sp1.addNumber(42);
		try {
			sp1.shortestSpan();  // only 1 element
		} catch (std::exception const & e) {
			std::cerr << "1 elem: " << e.what() << std::endl;
		}

		Span sp0(0);
		try {
			sp0.longestSpan();  // 0 elements
		} catch (std::exception const & e) {
			std::cerr << "0 elem: " << e.what() << std::endl;
		}
	}

	std::cout << "\n=== Large test (10000 numbers) ===" << std::endl;
	{
		std::srand(42);
		Span big(10000);

		// Fill with iterator range
		std::vector<int> src;
		for (int i = 0; i < 10000; ++i)
			src.push_back(std::rand() % 1000000);
		big.addNumbers(src.begin(), src.end());

		std::cout << "shortestSpan: " << big.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << big.longestSpan() << std::endl;
	}

	std::cout << "\n=== Copy test ===" << std::endl;
	{
		Span sp(5);
		sp.addNumber(10);
		sp.addNumber(20);
		Span sp2(sp);
		Span sp3(10);
		sp3 = sp;
		std::cout << "original longestSpan: " << sp.longestSpan() << std::endl;
		std::cout << "copy     longestSpan: " << sp2.longestSpan() << std::endl;
		std::cout << "assigned longestSpan: " << sp3.longestSpan() << std::endl;
	}

	return 0;
}
