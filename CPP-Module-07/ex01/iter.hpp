#ifndef ITER_HPP
# define ITER_HPP

// Non-const array version
template <typename T, typename F>
void iter(T * array, std::size_t const len, F func)
{
	for (std::size_t i = 0; i < len; ++i)
		func(array[i]);
}

// Const array version
template <typename T, typename F>
void iter(T const * array, std::size_t const len, F func)
{
	for (std::size_t i = 0; i < len; ++i)
		func(array[i]);
}

#endif
