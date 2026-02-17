#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <iomanip>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const & o) : _inputVec(o._inputVec) {}
PmergeMe & PmergeMe::operator=(PmergeMe const & o)
{
	if (this != &o) _inputVec = o._inputVec;
	return *this;
}
PmergeMe::~PmergeMe() {}

// ---------- parsing ----------

void PmergeMe::parseArgs(int argc, char* argv[])
{
	for (int i = 1; i < argc; ++i) {
		std::istringstream iss(argv[i]);
		long val;
		if (!(iss >> val) || val <= 0)
			throw std::runtime_error("Error");
		std::string rest;
		if (iss >> rest)
			throw std::runtime_error("Error");
		_inputVec.push_back(static_cast<int>(val));
	}
	if (_inputVec.empty())
		throw std::runtime_error("Error");
}

// ---------- Jacobsthal sequence ----------
// J(0)=0, J(1)=1, J(n)=J(n-1)+2*J(n-2)
// Returns insertion order indices for Ford-Johnson

std::vector<std::size_t> PmergeMe::jacobsthalSequence(std::size_t n)
{
	std::vector<std::size_t> result;
	if (n == 0) return result;

	// Build Jacobsthal numbers up to n
	std::vector<std::size_t> jac;
	jac.push_back(0);
	jac.push_back(1);
	while (jac.back() < n)
		jac.push_back(jac[jac.size()-1] + 2 * jac[jac.size()-2]);

	std::vector<bool> added(n + 1, false);

	for (std::size_t k = 2; k < jac.size(); ++k) {
		std::size_t hi = jac[k]     < n ? jac[k]     : n;
		std::size_t lo = jac[k - 1] + 1;
		// insert from hi down to lo
		for (std::size_t idx = hi; idx >= lo && idx > 0; --idx) {
			if (!added[idx]) {
				result.push_back(idx);
				added[idx] = true;
			}
		}
	}
	// any remaining
	for (std::size_t i = 1; i <= n; ++i) {
		if (!added[i]) result.push_back(i);
	}
	return result;
}

// ---------- vector implementation ----------

void PmergeMe::insertSortedVec(std::vector<int> & main,
                                std::vector<int> const & pend)
{
	std::vector<std::size_t> order = jacobsthalSequence(pend.size());

	for (std::size_t k = 0; k < order.size(); ++k) {
		std::size_t idx = order[k] - 1;  // 0-based
		if (idx >= pend.size()) continue;
		int val = pend[idx];

		// binary search upper bound in main
		std::vector<int>::iterator pos =
			std::lower_bound(main.begin(), main.end(), val);
		main.insert(pos, val);
	}
}

void PmergeMe::fordJohnsonVec(std::vector<int> & v)
{
	if (v.size() <= 1) return;

	// 1. Form pairs, track leftover
	bool hasStraggler = (v.size() % 2 != 0);
	int  straggler    = hasStraggler ? v.back() : 0;

	std::vector<std::pair<int,int> > pairs;
	for (std::size_t i = 0; i + 1 < v.size(); i += 2) {
		int a = v[i], b = v[i + 1];
		if (a > b) std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));  // (smaller, larger)
	}

	// 2. Recursively sort by the "larger" element of each pair
	std::vector<int> largers;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].second);
	fordJohnsonVec(largers);

	// 3. Rebuild pairs in the order largers were sorted
	// Create a lookup: larger value → smaller partner
	// (use the sorted largers to reorder pairs)
	std::vector<std::pair<int,int> > sortedPairs;
	// Since largers is now sorted, reorder pairs accordingly
	{
		// Build temp copy to match
		std::vector<std::pair<int,int> > tmp = pairs;
		for (std::size_t i = 0; i < largers.size(); ++i) {
			for (std::size_t j = 0; j < tmp.size(); ++j) {
				if (tmp[j].second == largers[i]) {
					sortedPairs.push_back(tmp[j]);
					tmp.erase(tmp.begin() + j);
					break;
				}
			}
		}
	}

	// 4. Main chain = all largers; pend = all smalls
	std::vector<int> main_chain(largers);
	std::vector<int> pend;
	for (std::size_t i = 0; i < sortedPairs.size(); ++i)
		pend.push_back(sortedPairs[i].first);

	// First pend element (partner of smallest large) is always <= main[0]
	main_chain.insert(main_chain.begin(), pend[0]);
	pend.erase(pend.begin());

	// 5. Insert remaining pend using Jacobsthal order
	insertSortedVec(main_chain, pend);

	// 6. Insert straggler if any
	if (hasStraggler) {
		std::vector<int>::iterator pos =
			std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
		main_chain.insert(pos, straggler);
	}

	v = main_chain;
}

// ---------- deque implementation ----------

void PmergeMe::insertSortedDeq(std::deque<int> & main,
                                std::deque<int> const & pend)
{
	std::vector<std::size_t> order = jacobsthalSequence(pend.size());

	for (std::size_t k = 0; k < order.size(); ++k) {
		std::size_t idx = order[k] - 1;
		if (idx >= pend.size()) continue;
		int val = pend[idx];

		std::deque<int>::iterator pos =
			std::lower_bound(main.begin(), main.end(), val);
		main.insert(pos, val);
	}
}

void PmergeMe::fordJohnsonDeq(std::deque<int> & d)
{
	if (d.size() <= 1) return;

	bool hasStraggler = (d.size() % 2 != 0);
	int  straggler    = hasStraggler ? d.back() : 0;

	std::vector<std::pair<int,int> > pairs;
	for (std::size_t i = 0; i + 1 < d.size(); i += 2) {
		int a = d[i], b = d[i + 1];
		if (a > b) std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	std::deque<int> largers;
	for (std::size_t i = 0; i < pairs.size(); ++i)
		largers.push_back(pairs[i].second);
	fordJohnsonDeq(largers);

	std::vector<std::pair<int,int> > sortedPairs;
	{
		std::vector<std::pair<int,int> > tmp = pairs;
		for (std::size_t i = 0; i < largers.size(); ++i) {
			for (std::size_t j = 0; j < tmp.size(); ++j) {
				if (tmp[j].second == largers[i]) {
					sortedPairs.push_back(tmp[j]);
					tmp.erase(tmp.begin() + j);
					break;
				}
			}
		}
	}

	std::deque<int> main_chain(largers);
	std::deque<int> pend;
	for (std::size_t i = 0; i < sortedPairs.size(); ++i)
		pend.push_back(sortedPairs[i].first);

	main_chain.insert(main_chain.begin(), pend[0]);
	pend.erase(pend.begin());

	insertSortedDeq(main_chain, pend);

	if (hasStraggler) {
		std::deque<int>::iterator pos =
			std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
		main_chain.insert(pos, straggler);
	}

	d = main_chain;
}

// ---------- sortAndDisplay ----------

void PmergeMe::sortAndDisplay() const
{
	// Print before
	std::cout << "Before:";
	for (std::size_t i = 0; i < _inputVec.size(); ++i)
		std::cout << " " << _inputVec[i];
	std::cout << std::endl;

	// --- vector sort ---
	std::vector<int> vec(_inputVec);
	struct timespec t1, t2;
	clock_gettime(CLOCK_MONOTONIC, &t1);
	fordJohnsonVec(vec);
	clock_gettime(CLOCK_MONOTONIC, &t2);
	double vecTime = (t2.tv_sec - t1.tv_sec) * 1e6
	               + (t2.tv_nsec - t1.tv_nsec) / 1e3;

	// Print after
	std::cout << "After: ";
	for (std::size_t i = 0; i < vec.size(); ++i)
		std::cout << " " << vec[i];
	std::cout << std::endl;

	// --- deque sort ---
	std::deque<int> deq(_inputVec.begin(), _inputVec.end());
	struct timespec t3, t4;
	clock_gettime(CLOCK_MONOTONIC, &t3);
	fordJohnsonDeq(deq);
	clock_gettime(CLOCK_MONOTONIC, &t4);
	double deqTime = (t4.tv_sec - t3.tv_sec) * 1e6
	               + (t4.tv_nsec - t3.tv_nsec) / 1e3;

	std::cout << std::fixed << std::setprecision(5);
	std::cout << "Time to process a range of " << _inputVec.size()
	          << " elements with std::vector : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _inputVec.size()
	          << " elements with std::deque  : " << deqTime << " us" << std::endl;
}
