#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <stdexcept>

class Span
{
public:
	Span(unsigned int n);
	Span(Span const & other);
	Span & operator=(Span const & other);
	~Span();

	void         addNumber(int n);

	// Add range of iterators in a single call
	template <typename Iterator>
	void addNumbers(Iterator first, Iterator last)
	{
		while (first != last) {
			addNumber(*first);
			++first;
		}
	}

	int shortestSpan() const;
	int longestSpan() const;

private:
	Span();  // forbidden

	unsigned int       _maxSize;
	std::vector<int>   _numbers;
};

#endif
