#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(PmergeMe const & other);
	PmergeMe & operator=(PmergeMe const & other);
	~PmergeMe();

	void parseArgs(int argc, char* argv[]);
	void sortAndDisplay() const;

private:
	std::vector<int> _inputVec;

	// Ford-Johnson for vector
	static void fordJohnsonVec(std::vector<int> & v);
	static void insertSortedVec(std::vector<int> & main,
	                            std::vector<int> const & pend);

	// Ford-Johnson for deque
	static void fordJohnsonDeq(std::deque<int> & d);
	static void insertSortedDeq(std::deque<int> & main,
	                            std::deque<int> const & pend);

	static std::vector<std::size_t> jacobsthalSequence(std::size_t n);
};

#endif
