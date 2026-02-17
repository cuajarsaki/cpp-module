#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
Array<T>::Array()
	: _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: _data(new T[n]()), _size(n)
{
}

template <typename T>
Array<T>::Array(Array<T> const & other)
	: _data(new T[other._size]()), _size(other._size)
{
	for (unsigned int i = 0; i < _size; ++i)
		_data[i] = other._data[i];
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & other)
{
	if (this != &other) {
		delete[] _data;
		_size = other._size;
		_data = new T[_size]();
		for (unsigned int i = 0; i < _size; ++i)
			_data[i] = other._data[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T & Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
T const & Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

#endif

template <typename T>
T & Array<T>::operator[](int index)
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[static_cast<unsigned int>(index)];
}

template <typename T>
T const & Array<T>::operator[](int index) const
{
	if (index < 0 || static_cast<unsigned int>(index) >= _size)
		throw std::out_of_range("Index out of bounds");
	return _data[static_cast<unsigned int>(index)];
}
