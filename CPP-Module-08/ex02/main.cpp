#include <iostream>
#include <stack>
#include <list>
#include "MutantStack.hpp"

// Subject's test with MutantStack
static void testMutantStack()
{
	std::cout << "=== MutantStack (subject test) ===" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;  // 17
	mstack.pop();
	std::cout << mstack.size() << std::endl; // 1

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);  // copy into plain stack - must compile
	(void)s;
}

// Same logic with std::list for comparison
static void testList()
{
	std::cout << "\n=== std::list (same logic) ===" << std::endl;

	std::list<int> lst;

	lst.push_back(5);
	lst.push_back(17);

	std::cout << lst.back() << std::endl;  // 17 (= top)
	lst.pop_back();
	std::cout << lst.size() << std::endl;  // 1

	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);

	std::list<int>::iterator it  = lst.begin();
	std::list<int>::iterator ite = lst.end();

	++it;
	--it;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
}

// Extra: reverse iterators + const iterators
static void testExtras()
{
	std::cout << "\n=== Extra: reverse + const iterators ===" << std::endl;

	MutantStack<int> ms;
	for (int i = 1; i <= 5; ++i)
		ms.push(i * 10);  // 10 20 30 40 50

	// forward
	std::cout << "Forward:  ";
	for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// reverse
	std::cout << "Reverse:  ";
	for (MutantStack<int>::reverse_iterator it = ms.rbegin(); it != ms.rend(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// const
	const MutantStack<int> cms(ms);
	std::cout << "Const:    ";
	for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// custom Container: list as underlying container
	MutantStack<int, std::list<int> > lstack;
	lstack.push(100);
	lstack.push(200);
	lstack.push(300);
	std::cout << "ListStack top: " << lstack.top() << std::endl;
	std::cout << "ListStack iter: ";
	for (MutantStack<int, std::list<int> >::iterator it = lstack.begin();
	     it != lstack.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

int main()
{
	testMutantStack();
	testList();
	testExtras();
	return 0;
}
